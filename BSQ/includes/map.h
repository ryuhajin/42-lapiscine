/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:31:24 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 03:36:08 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map_info
{
	int		line;
	char	empty;
	char	obstacle;
	char	full;
}			t_map_info;

t_map_info	*get_map_info(char *str);
int			run(char **input, t_map_info *info);
int			get_map_height(int **map);
int			get_map_width(int **map);

#endif
