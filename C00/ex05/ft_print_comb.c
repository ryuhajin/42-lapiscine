/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:40:13 by dayou             #+#    #+#             */
/*   Updated: 2023/02/15 19:54:19 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	numbers[3];

	numbers[0] = '0';
	while (numbers[0] != '7' + 1)
	{
		numbers[1] = numbers[0] + 1;
		while (numbers[1] != '8' + 1)
		{
			numbers[2] = numbers[1] + 1;
			while (numbers[2] != '9' + 1)
			{
				write(1, &numbers[0], 1);
				write(1, &numbers[1], 1);
				write(1, &numbers[2], 1);
				if (numbers[0] < '7')
				{
					write(1, ", ", 2);
				}
				numbers[2]++;
			}
			numbers[1]++;
		}
		numbers[0]++;
	}
}

/* int	main(void)
{
	ft_print_comb();

	return (0);
} */