/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:19:12 by dayou             #+#    #+#             */
/*   Updated: 2023/02/15 19:59:59 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	negative_check(int nb, int int_min_check)
{
	if (int_min_check == 1)
		nb += 1;
	nb *= -1;
	write(1, "-", 1);
	return (nb);
}

char	*int_to_char(int nb, char numbers[], int int_min_check)
{
	int	idx;

	idx = 0;
	while (nb != 0)
	{
		numbers[idx] = (nb % 10) + '0';
		nb = nb / 10;
		idx++;
	}
	if (int_min_check == 1)
		numbers[0] += 1;
	numbers[idx] = 0;
	return (numbers);
}

void	ft_putnbr(int nb)
{
	char	numbers[11];
	int		idx;
	int		is_int_min;

	idx = 0;
	is_int_min = 0;
	if (nb == -2147483648)
		is_int_min = 1;
	if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
		nb = negative_check(nb, is_int_min);
	int_to_char(nb, numbers, is_int_min);
	while (numbers[idx])
		idx++;
	idx -= 1;
	while (idx >= 0)
	{
		write(1, &(numbers[idx]), 1);
		idx--;
	}
}

/* int	main(void)
{
	ft_putnbr(42);
	printf("\n");
	ft_putnbr(INT_MIN);
	printf("\n");
	ft_putnbr(INT_MAX);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(-1);
	printf("\n");
	return (0);
} */
