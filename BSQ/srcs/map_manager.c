/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:51:08 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 02:20:43 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "square.h"
#include "my_string.h"
#include <stdlib.h>

void	print_map(int **map, t_square *square, t_map_info *info);
int		generate(char **input, int **map, t_map_info *info);
void	init(int **map, int width, int height);
int		**allocate_map(int width, int height);

int	run(char **input, t_map_info *info)
{
	int			**map;
	int			width;
	int			height;
	t_square	*square;

	width = get_input_width(input);
	height = get_input_height(input);
	map = allocate_map(width, height);
	if (!map)
		return (0);
	init(map, width, height);
	if (!generate(input, map, info))
		return (0);
	square = find_square(map, width, height);
	if (!square)
		return (0);
	print_map(map, square, info);
	return (1);
}

int	generate(char **input, int **map, t_map_info *info)
{
	int		i;
	int		j;
	int		width;
	int		height;
	char	c;

	width = get_input_width(input);
	height = get_input_height(input);
	i = 0;
	while (++i <= height)
	{
		j = 0;
		while (++j <= width)
		{
			c = input[i - 1][j - 1];
			if (c == info->empty)
				map[i][j] = 1;
			else if (c == info->obstacle)
				map[i][j] = 0;
			else
				return (0);
		}
	}
	return (1);
}

void	init(int **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height + 2)
		map[i++][0] = 0;
	j = 0;
	while (j < width + 2)
		map[0][j++] = 0;
	i = 0;
	while (i < height + 2)
		map[i++][width + 1] = -1;
	j = 0;
	while (j < width + 2)
		map[height + 1][j++] = -1;
}

int	**allocate_map(int width, int height)
{
	int	**map;
	int	idx;

	map = (int **)malloc(sizeof(int *) * (height + 2));
	if (!map)
		return (0);
	idx = 0;
	while (idx < height + 2)
	{
		map[idx] = (int *)malloc(sizeof(int) * (width + 2));
		if (!map[idx])
			return (0);
		idx++;
	}
	return (map);
}
