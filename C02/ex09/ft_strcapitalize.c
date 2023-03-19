/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:00:51 by dayou             #+#    #+#             */
/*   Updated: 2023/02/18 00:08:15 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_str_is_strlowcase(char *str)
{
	char	*temp;

	temp = str;
	if (*str == 0)
		return (str);
	while (*str)
	{
		if ('A' <= *str && 'Z' >= *str)
			*str += 32;
		str++;
	}
	return (temp);
}

char	*ft_strcapitalize(char *str)
{
	char	*temp;
	int		idx;

	temp = ft_str_is_strlowcase(str);
	idx = 0;
	while (str[idx])
	{
		if (('a' <= str[idx] && 'z' >= str[idx]) && \
			!('0' <= str[idx - 1] && '9' >= str[idx - 1]) && \
			!('a' <= str[idx - 1] && 'z' >= str[idx - 1]) && \
			!('A' <= str[idx - 1] && 'Z' >= str[idx - 1]))
			str[idx] -= 32;
		idx++;
	}
	return (temp);
}
