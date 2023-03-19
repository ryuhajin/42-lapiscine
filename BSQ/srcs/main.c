/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:16:52 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 12:31:44 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "file_manager.h"
#include "map.h"
#include "my_string.h"
#include "printer.h"
#include "square.h"
#include <stdio.h>
#include <stdlib.h>

void	free_(char **input_arr)
{
	int	i;

	i = 0;
	if (input_arr != NULL)
	{
		while (input_arr[i] != NULL)
			free(input_arr[i++]);
	}
}

void	run_bsq_stdin(void)
{
	char	**input_arr;
	char	*file;
	int		i;

	file = 0;
	input_arr = 0;
	if (!read_fd(0, &file))
	{
		print_error("map error");
		return ;
	}
	input_arr = ft_split(file);
	free(file);
	if (!check_map(input_arr[0], input_arr + 1))
	{
		print_error("map error");
		return ;
	}
	run(input_arr + 1, get_map_info(input_arr[0]));
	i = 0;
	free_(input_arr);
	free(input_arr);
}

void	run_bsq_file(char *filename)
{
	char	**input_arr;
	char	*file;
	int		i;

	file = 0;
	input_arr = 0;
	if (!read_file(filename, &file))
	{
		print_error("file error");
		return ;
	}
	input_arr = ft_split(file);
	free(file);
	if (!check_map(input_arr[0], input_arr + 1))
	{
		print_error("map error");
		return ;
	}
	run(input_arr + 1, get_map_info(input_arr[0]));
	i = 0;
	free_(input_arr);
	free(input_arr);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		run_bsq_stdin();
	else if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			run_bsq_file(av[i]);
			i++;
		}
	}
	return (0);
}
