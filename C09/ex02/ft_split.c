/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:21:53 by dayou             #+#    #+#             */
/*   Updated: 2023/03/01 20:38:26 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_word(char *str, int *charset_check)
{
	int	idx;
	int	size;

	idx = 0;
	size = 0;
	while (str[idx])
	{
		if (charset_check[(int)str[idx]] == 0 && \
			charset_check[(int)str[idx + 1]] == 1)
			size++;
		idx++;
	}
	return (size);
}

void	copy_words(char **split, char *str, int *charset_check, int size)
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
		while (charset_check[(int)str[idx]] == 1)
			idx++;
		while (charset_check[(int)str[idx]] == 0)
		{
			split[i][j] = str[idx];
			j++;
			idx++;
		}
		split[i][j] = 0;
		i++;
	}
}

void	alloc_words(char **split, char *str, int *charset_check, int size)
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
		while (charset_check[(int)str[idx]] == 1)
			idx++;
		while (charset_check[(int)str[idx]] == 0)
		{
			idx++;
			strlen++;
		}
		new_str = (char *)malloc(sizeof(char) * (strlen + 1));
		split[i] = new_str;
		i++;
	}
	split[size] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		idx;
	int		size;
	char	**split;
	int		charset_check[256];

	idx = 0;
	size = 0;
	while (idx < 256)
	{
		charset_check[idx] = 0;
		idx++;
	}
	idx = 0;
	while (charset[idx])
	{
		charset_check[(int)charset[idx]] = 1;
		idx++;
	}
	charset_check[0] = 1;
	size = count_word(str, charset_check);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	split[size] = 0;
	alloc_words(split, str, charset_check, size);
	copy_words(split, str, charset_check, size);
	return (split);
}

#include <stdio.h>

int main(void)
{
	char *gubun = "~";
	char *str = "~123~abc        ~ sdfsdfjsdfkjsdfjkfjlsdjflksdjfkl";
	char **split_ = ft_split(str, gubun);
	int i = 0;

	while (split_[i])
	{
		printf("%s\n" , split_[i]);
		i++;
	}
}
