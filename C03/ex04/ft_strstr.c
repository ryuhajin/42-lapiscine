/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:53:10 by dayou             #+#    #+#             */
/*   Updated: 2023/02/20 11:50:12 by dayou            ###   ########.fr       */
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

unsigned int	str_check(char *str, char *to_find, unsigned int idx)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(to_find);
	while (str[idx] == to_find[i] && i < len)
	{
		idx++;
		i++;
	}
	if (to_find[i] == 0)
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	idx;
	unsigned int	same_check;

	idx = 0;
	same_check = 0;
	if (*to_find == 0)
		return (str);
	while (str[idx] != 0)
	{
		if (str[idx] == to_find[0])
			same_check = (str_check(str, to_find, idx));
		if (same_check == 1)
			return (&str[idx]);
		idx++;
	}
	return (0);
}
