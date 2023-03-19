/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:06:31 by dayou             #+#    #+#             */
/*   Updated: 2023/02/20 20:00:36 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i != size / 2)
	{
		ft_swap(&tab[i], &tab[j]);
		j--;
		i++;
	}
}

/* int	main(void)
{
	int	arr[5];
	int	arr_2[4];

	arr[5] = {1, 2, 3, 4, 5};
	arr_2[4] = {1, 2, 3, 4};
	ft_rev_int_tab(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("arr: %d \n", arr[i]);
	}
	ft_rev_int_tab(arr_2, 4);
	for (int i = 0; i < 4; i++)
	{
		printf("arr_2: %d \n", arr_2[i]);
	}
	return (0);
} */
