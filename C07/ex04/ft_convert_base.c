/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:38:36 by dayou             #+#    #+#             */
/*   Updated: 2023/02/27 11:20:38 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_check(char *base);
int		ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*number_is_zero(char *base_to)
{
	char	*str;

	str = (char *)malloc(sizeof(str) * 2);
	str[0] = base_to[0];
	str[1] = 0;
	return (str);
}

int	nbr_len_plz(long long nbr, int base_number)
{
	int	cnt;

	cnt = 0;
	while (nbr > 0)
	{
		nbr /= base_number;
		cnt++;
	}
	return (cnt);
}

void	str_maker(long long nbr, char *base_to, char *str, int minus)
{
	int	base_len;
	int	nbr_len;

	base_len = ft_strlen(base_to);
	nbr_len = nbr_len_plz(nbr, ft_strlen(base_to));
	while (nbr_len > 0)
	{
		str[nbr_len - 1 + minus] = base_to[nbr % base_len];
		nbr /= base_len;
		nbr_len--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	number;
	int			minus;
	int			nbr_len;
	char		*str;

	minus = 0;
	if (base_check(base_from) == -1 || base_check(base_to) == -1)
		return (0);
	number = (long long)ft_atoi_base(nbr, base_from);
	if (number == 0)
		return (number_is_zero(base_to));
	if (number < 0)
	{
		minus += 1;
		number *= -1;
	}
	nbr_len = nbr_len_plz(number, ft_strlen(base_to));
	str = (char *)malloc(sizeof(char) * (nbr_len + minus + 1));
	str[nbr_len + minus] = '\0';
	if (minus == 1)
		str[0] = '-';
	str_maker(number, base_to, str, minus);
	return (str);
}
