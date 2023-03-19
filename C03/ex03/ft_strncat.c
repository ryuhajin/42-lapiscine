/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:38:24 by dayou             #+#    #+#             */
/*   Updated: 2023/02/20 14:15:44 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*temp;
	unsigned int	idx;

	temp = dest;
	idx = 0;
	while (*dest)
		dest++;
	while ((*dest != 0 || src[idx] != 0) && idx < nb)
	{
		*dest = src[idx];
		idx++;
		dest++;
	}
	*dest = 0;
	return (temp);
}
