/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:18:03 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 02:28:43 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include <stdlib.h>
#include "init.h"

void	set_square(t_square *square, int i, int j, int len);
int		recurrence_relation(int **map, int i, int j);
int		min(int num1, int num2, int num3);

t_square	*find_square(int **map, int width, int height)
{
	int			i;
	int			j;
	int			max;
	t_square	*square;

	square = (t_square *)malloc(sizeof(t_square));
	if (!square)
		return (0);
	init_find_square(&i, &max, square);
	while (++i <= height)
	{
		j = 0;
		while (++j <= width)
		{
			if (map[i][j] == 0)
				continue ;
			map[i][j] = recurrence_relation(map, i, j);
			if (map[i][j] > max)
			{
				max = map[i][j];
				set_square(square, i, j, max);
			}
		}
	}
	return (square);
}

int	recurrence_relation(int **map, int i, int j)
{
	return (min(map[i - 1][j - 1], map[i - 1][j], map[i][j - 1]) + 1);
}

int	min(int num1, int num2, int num3)
{
	int	min;

	min = num1;
	if (num2 < min)
		min = num2;
	if (num3 < min)
		min = num3;
	return (min);
}
