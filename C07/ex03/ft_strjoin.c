/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:06:17 by dayou             #+#    #+#             */
/*   Updated: 2023/02/27 19:10:50 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int	sep_in_str(char *join_str, char *sep, int idx)
{
	int	j;

	j = 0;
	while (sep[j])
	{
		join_str[idx] = sep[j];
		idx++;
		j++;
	}
	return (idx);
}

void	str_maker(char *join_str, char **strs, char *sep, int size)
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
		while (strs[i][j])
		{
			join_str[idx] = strs[i][j];
			idx++;
			j++;
		}
		if (i < size - 1)
			idx = sep_in_str(join_str, sep, idx);
		i++;
	}
}

char	*size_is_zero(void)
{
	char	*join_str;

	join_str = (char *)malloc(sizeof(char));
	join_str[0] = 0;
	return (join_str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		join_len;
	char	*join_str;

	i = 0;
	j = 0;
	if (size < 1)
		return (size_is_zero());
	join_len = ft_strlen(sep) * (size - 1);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
		}
		join_len += j;
		i++;
	}
	join_str = (char *)malloc(sizeof(char) * (join_len + 1));
	join_str[join_len] = 0;
	str_maker(join_str, strs, sep, size);
	return (join_str);
}

/* #include <stdio.h>
int	main(void)
{
	char str0[] = "abc";
	char str1[] = "def";
	char str2[] = "123";
	char str3[] = "234";
	char str4[] = "abc";
	char * sep = "---------";
	char * strs[6] = {str0, str1, str2, str3, str4};
	printf("%s \n", ft_strjoin(5, strs, sep));
	return (0);
}  */
