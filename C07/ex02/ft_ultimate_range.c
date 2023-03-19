/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:16:09 by dayou             #+#    #+#             */
/*   Updated: 2023/02/27 11:34:16 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*ptr;

	size = max - min;
	i = 0;
	if (min >= max)
		return (0);
	ptr = (int *)malloc(sizeof(int) * size);
	*range = ptr;
	while (i < size)
	{
		ptr[i] = min;
		min++;
		i++;
	}
	return (size);
}

 #include <stdio.h>
int	main(void)
{
	int min = -1;
	int max = 2;
	int i = 0;
	int **pp;
	int *p;

	pp = &p;

	ft_ultimate_range(pp, min, max);

	while (i < 3)
	{
		printf("%d\n", p[i]);
		i++;
	}
	return (0);
} 
