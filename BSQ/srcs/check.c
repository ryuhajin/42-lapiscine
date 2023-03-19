/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:01:05 by dayou             #+#    #+#             */
/*   Updated: 2023/03/02 02:28:03 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//프로그램은 1 n개의 파일을 매개변수로 처리해야 합니다.

//argc > 1; 파일이 av로  들어오는가 (?)

//9 .ox (9줄 .o    x) == 첫번째 행

//모든 행의 길이가 같아야합니다.
// 두번째 행만 
// 줄 수 카운트
// ->  맨 첫행과 길이가 다르면 리턴 0 = 에러

#include "my_string.h"
#include "my_char.h"
#include "map.h"
#include "my_stdlib.h"

int	check_row_len(char **input);
int	check_map_info(char *map_info, char **input);
int	check_map_char(char **input, char empty, char obstacle);

int	check_map(char *map_info, char **input)
{
	int	len;

	len = ft_strlen(map_info);
	if (!map_info || !input)
		return (0);
	if (!check_row_len(input))
		return (0);
	if (!check_map_info(map_info, input))
		return (0);
	if (!check_map_char(input, map_info[len - 3], map_info[len -2]))
		return (0);
	return (1);
}

int	check_row_len(char **input)
{
	int	width;
	int	idx;

	idx = 0;
	width = get_input_width(input);
	if (width == 0)
		return (0);
	while (*input)
	{
		if ((*input)[idx])
			idx++;
		else
		{
			if (width != idx)
				return (0);
			input++;
			idx = 0;
		}
	}
	return (1);
}

int	check_map_info(char *map_info, char **input)
{
	int		len;
	int		line;
	char	empty;
	char	obstacle;
	char	full;

	len = ft_strlen(map_info);
	if (len < 4)
		return (0);
	line = ft_atoi(ft_strncpy(map_info, len - 3));
	if (line <= 0 || line != get_input_height(input))
		return (0);
	empty = map_info[len - 3];
	obstacle = map_info[len - 2];
	full = map_info[len - 1];
	if (empty == obstacle || empty == full || obstacle == full)
		return (0);
	if (!is_printable(empty) || !is_printable(obstacle)
		|| !is_printable(full))
		return (0);
	return (1);
}

int	check_map_char(char **input, char empty, char obstacle)
{
	int	width;
	int	height;
	int	i;
	int	j;
	int	cnt;

	width = get_input_width(input);
	height = get_input_height(input);
	i = -1;
	cnt = 0;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (input[i][j] == empty)
				cnt++;
			else if (input[i][j] != obstacle)
				return (0);
		}
	}
	if (cnt == 0)
		return (0);
	return (1);
}
