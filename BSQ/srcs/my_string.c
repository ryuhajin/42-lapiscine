/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:30:21 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 03:32:01 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	get_input_width(char **input)
{
	int	width;

	width = 0;
	while ((*input)[width])
		width++;
	return (width);
}

int	get_input_height(char **input)
{
	int	height;

	height = 0;
	while (input[height])
		height++;
	return (height);
}

char	*ft_strncpy(char *src, int n)
{
	int		i;
	char	*dest;

	if (n < 0)
		return (0);
	if (n == 0)
		return (src);
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	dest[n] = '\0';
	i = 0;
	while (i < n)
	{
		if (src[i] == '\0')
			break ;
		dest[i] = src[i];
		i++;
	}
	if (ft_strlen(src) < n)
	{
		while (i < n)
			dest[i++] = '\0';
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}
