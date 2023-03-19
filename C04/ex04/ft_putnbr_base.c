/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:58:10 by dayou             #+#    #+#             */
/*   Updated: 2023/03/01 19:25:55 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	print_nbr(long long nbr_, int base_number, char *base)
{
	if (nbr_ > 0)
	{
		print_nbr(nbr_ / base_number, base_number, base);
		write(1, &base[nbr_ % base_number], 1);
	}
}

int	base_check(char *str)
{
	int	check[256];
	int	idx;

	idx = 0;
	if (str[0] == 0 || str[1] == 0)
		return (-1);
	while (idx < 256)
	{
		check[idx] = 0;
		idx++;
	}
	while (*str)
	{
		idx = *str;
		if (*str == '-' || *str == '+')
			return (-1);
		check[idx] += 1;
		if (check[idx] > 1)
			return (-1);
		str++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			idx;
	int			base_number;
	long long	nbr_;

	idx = 0;
	base_number = base_check(base);
	if (base_number == -1)
		return ;
	base_number = ft_strlen(base);
	if (nbr == 0)
		write(1, &base[0], 1);
	nbr_ = (long long)nbr;
	if (nbr_ < 0)
	{
		nbr_ *= -1;
		write(1, "-", 1);
	}
	print_nbr(nbr_, base_number, base);
}

#include<stdio.h>
int main(void)
{
    char *nbr = "++++1234";
    char *base_from = "0123456789abcdef";
	char *base_to = "0123456789";
    printf("base_from_value: %d\n", ft_spc(nbr,base_from,base_len_check(base_from)));
	printf("base_to_value: %s\n", ft_convert_base (nbr, base_from, base_to));
    return (0);
}
