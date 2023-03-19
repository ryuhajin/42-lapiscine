/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:16:41 by dayou             #+#    #+#             */
/*   Updated: 2023/02/15 19:53:55 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	z;

	z = 'z';
	while (z != 'a' - 1)
	{
		write(1, &z, 1);
		z--;
	}
}

/* int	main(void)
{
	ft_print_reverse_alphabet();
	return (0);
} */