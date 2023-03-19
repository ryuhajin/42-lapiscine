/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:21:33 by dayou             #+#    #+#             */
/*   Updated: 2023/02/20 14:58:24 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	idx = 0;
	i = 0;
	while (dest[i] && i < dest_len)
		i++;
	while (src[idx] && i + 1 < size)
	{
		dest[i] = src[idx];
		i++;
		idx++;
	}
	dest[i] = 0;
	if (size < dest_len)
		return (src_len + size);
	return (dest_len + src_len);
}
