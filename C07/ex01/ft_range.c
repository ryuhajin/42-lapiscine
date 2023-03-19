/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:41:59 by dayou             #+#    #+#             */
/*   Updated: 2023/02/27 11:20:25 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	size;
	int	i;

	size = max - min;
	i = 0;
	if (min >= max)
		return (0);
	range = (int *)malloc(sizeof(int) * size);
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}

/* #include <stdio.h>

int	main(void)
{
	int *p = ft_range(-1, 5);
	int min;
	int max;

	min = -1;
	max = 5;
	int i = 0;
	while (i < max - min)
	{
		printf("%d ", p[i]);
		i++;
	}

	return (0);
} */