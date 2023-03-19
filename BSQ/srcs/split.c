/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:23 by dayou             #+#    #+#             */
/*   Updated: 2023/03/02 03:19:24 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_word(char *str)
{
	int	idx;
	int	size;

	idx = 0;
	size = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			size++;
		idx++;
	}
	return (size);
}

void	copy_words(char **split, char *str, int size)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	j = 0;
	idx = 0;
	while (i < size)
	{
		j = 0;
		while (str[idx] == '\n')
			idx++;
		while (str[idx] && str[idx] != '\n')
		{
			split[i][j] = str[idx];
			j++;
			idx++;
		}
		i++;
	}
}

void	alloc_words(char **split, char *str, int size)
{
	int		i;
	int		idx;
	int		strlen;
	char	*new_str;

	i = 0;
	idx = 0;
	strlen = 0;
	while (i < size)
	{
		strlen = 0;
		while (str[idx] == '\n')
		{
			idx++;
		}
		while (str[idx] && str[idx] != '\n')
		{
			idx++;
			strlen++;
		}
		new_str = (char *)malloc(sizeof(char) * (strlen + 1));
		new_str[strlen] = 0;
		split[i] = new_str;
		i++;
	}
}

char	**ft_split(char *str)
{
	int		size;
	char	**split;

	size = count_word(str);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	split[size] = 0;
	alloc_words(split, str, size);
	copy_words(split, str, size);
	return (split);
}
