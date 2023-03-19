/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:19:31 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 01:44:48 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "square.h"
#include "map.h"
#include "my_string.h"

int	get_map_width(int **map);
int	get_map_height(int **map);

void	print_map(int **map, t_square *square, t_map_info *info)
{
	int	i;
	int	j;
	int	width;
	int	height;

	width = get_map_width(map);
	height = get_map_height(map);
	i = 1;
	while (i < height)
	{
		j = 1;
		while (j < width)
		{
			if (map[i][j] == 0)
				write(1, &(info->obstacle), 1);
			else if ((square->i - square->len < i && i <= square->i)
				&& (square->j - square->len < j && j <= square->j))
				write(1, &(info->full), 1);
			else
				write(1, &(info->empty), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	print_error(char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	write(1, "\n", 1);
	return (-1);
}
