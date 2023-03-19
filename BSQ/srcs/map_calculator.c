/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 01:48:51 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 02:29:34 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "my_string.h"
#include <stdlib.h>
#include <my_stdlib.h>

t_map_info	*get_map_info(char *str)
{
	t_map_info	*info;
	int			len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	info = (t_map_info *)malloc(sizeof(t_map_info));
	info->line = ft_atoi(ft_strncpy(str, len - 3));
	info->empty = str[len -3];
	info->obstacle = str[len - 2];
	info->full = str[len - 1];
	return (info);
}	

int	get_map_height(int **map)
{
	int	height;

	height = 0;
	while (map[height][0] != -1)
		height++;
	return (height);
}

int	get_map_width(int **map)
{
	int	width;

	width = 0;
	while (map[0][width] != -1)
		width++;
	return (width);
}
