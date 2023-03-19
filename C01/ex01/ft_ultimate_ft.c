/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:59:21 by dayou             #+#    #+#             */
/*   Updated: 2023/02/20 20:03:11 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

#include <stdio.h>

int	main(void)
{
	int	a;
	int	*nbr;
	int	**nbr_2;
	int	***nbr_3;
	int	****nbr_4;
	int	*****nbr_5;
	int	******nbr_6;
	int	*******nbr_7;
	int	********nbr_8;

	a = 0;
	printf("a : %d\n", a);
	nbr = &a;
	nbr_2 = &nbr;
	nbr_3 = &nbr_2;
	nbr_4 = &nbr_3;
	nbr_5 = &nbr_4;
	nbr_6 = &nbr_5;
	nbr_7 = &nbr_6;
	nbr_8 = &nbr_7;
	ft_ultimate_ft(&nbr_8);
	printf("a : %d\n", a);
	return (0);
}
