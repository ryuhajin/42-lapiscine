/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:09:39 by dayou             #+#    #+#             */
/*   Updated: 2023/02/19 16:42:39 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*temp;
	unsigned int	i;

	i = 0;
	temp = dest;
	while (*src && i < n)
	{
		*dest++ = *src++;
		i++;
	}
	while (i < n)
	{
		*dest = 0;
		dest++;
		i++;
	}
	return (temp);
}
