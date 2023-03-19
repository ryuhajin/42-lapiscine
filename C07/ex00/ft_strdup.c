/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:30:29 by dayou             #+#    #+#             */
/*   Updated: 2023/02/27 11:20:26 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (*src)
	{
		src++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*new_src;
	int		src_len;
	int		idx;

	idx = 0;
	src_len = ft_strlen(src);
	new_src = (char *)malloc(sizeof(char) * (src_len + 1));
	if (new_src == NULL)
		return (NULL);
	while (src[idx])
	{
		new_src[idx] = src[idx];
		idx++;
	}
	new_src[idx] = 0;
	return (new_src);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%s", ft_strdup("abcdefg"));

	return (0);
} */