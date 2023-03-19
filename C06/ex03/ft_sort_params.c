/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:29:07 by dayou             #+#    #+#             */
/*   Updated: 2023/02/23 16:26:18 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx])
		idx++;
	return (s1[idx] - s2[idx]);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_argv(char *s1, char *s2, int i)
{
	int	j;

	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(s1, s2) > 0)
				ft_swap(&s1, &s2);
			j++;
		}
		i--;
	}
}

void	print_argv(int argc, char **argv, int i)
{
	int	j;

	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &(argv[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = argc - 1;
	while (j > 1)
	{
		i = 1;
		while (i < j)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
				ft_swap(&argv[i], &argv[i + 1]);
			i++;
		}
		j--;
	}
	i = 1;
	print_argv(argc, argv, i);
	return (0);
}
