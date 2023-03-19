/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:23:45 by dayou             #+#    #+#             */
/*   Updated: 2023/02/15 19:54:27 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	int_to_char(int numbers)
{
	int	first_number;
	int	second_number;

	first_number = numbers % 10 + '0';
	second_number = (numbers / 10) % 10 + '0';
	write(1, &second_number, 1);
	write(1, &first_number, 1);
}

void	ft_print_comb2(void)
{
	int	numbers_1;
	int	numbers_2;

	numbers_1 = 100;
	while (numbers_1 <= 198)
	{
		numbers_2 = numbers_1 + 1;
		while (numbers_2 <= 199)
		{
			int_to_char(numbers_1);
			write(1, " ", 1);
			int_to_char(numbers_2);
			if (numbers_1 < 198)
			{
				write(1, ", ", 2);
			}
			numbers_2++;
		}
		numbers_1++;
	}
}

/* int	main(void)
{
	ft_print_comb2();
	return (0);
} */