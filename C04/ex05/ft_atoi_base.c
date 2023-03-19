/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:15:11 by dayou             #+#    #+#             */
/*   Updated: 2023/03/01 19:27:21 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	base_check(char *base)
{
	int	check[256];
	int	idx;

	idx = 0;
	if (base[0] == 0 || base[1] == 0)
		return (-1);
	while (idx < 256)
	{
		check[idx] = 0;
		idx++;
	}
	while (*base)
	{
		idx = *base;
		if (*base == '-' || *base == '+' || (*base >= 9 && *base <= 13)
			|| *base == 32)
			return (-1);
		check[idx] += 1;
		if (check[idx] > 1)
			return (-1);
		base++;
	}
	return (1);
}

int	ft_atoi(char *str, int *base_str, int base_number)
{
	int	n_p_check;
	int	number;

	n_p_check = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n_p_check *= -1;
		str++;
	}
	while (*str)
	{
		if (base_str[(int)*str] == -1)
			break ;
		number *= base_number;
		number += base_str[(int)*str];
		str++;
	}
	number *= n_p_check;
	return (number);
}

int	str_to_base(char *str, char *base, int base_number)
{
	int	base_str[256];
	int	i;
	int	number;
	int	n_p_check;

	i = 0;
	number = 0;
	n_p_check = 1;
	while (i <= 255)
	{
		base_str[i] = -1;
		i++;
	}
	i = 0;
	while (*base)
	{
		base_str[(int)*base] = i;
		i++;
		base++;
	}
	number = ft_atoi(str, base_str, base_number);
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_number;
	int	number;

	base_number = base_check(base);
	if (base_number == -1)
		return (0);
	base_number = ft_strlen(base);
	number = str_to_base(str, base, base_number);
	return (number);
}

#include<stdio.h>
int main(void)
{
    char *nbr = "999999";
    char *base_from = "0123456789abcdef";
	// char *base_to = "0123456789";
    printf("base_from_value: %d\n", ft_atoi_base(nbr, base_from));
	// printf("base_to_value: %s\n", ft_convert_base (nbr, base_from, base_to));
    return (0);
}
