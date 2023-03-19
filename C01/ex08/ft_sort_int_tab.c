/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:31:17 by dayou             #+#    #+#             */
/*   Updated: 2023/02/20 20:00:43 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (j > 0)
	{
		i = 0;
		while (i < j)
		{
			if (tab[i] > tab[i + 1])
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		j--;
	}
}

/* int	main(void)
{
	int arr[10] = {0, 9, 6, 2, 1, 4, 8, 3, 5, 7};
	int arr_2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr_3[5] = {4, 3, 2, 1, 0};
	int arr_4[5] = {0, 1, 2, 3, 4};
	ft_sort_int_tab(arr, 0);
	for (int i = 0; i < 10; i++)
	{
		printf("arr: %d \n", arr[i]);
	}
	ft_sort_int_tab(arr_2, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("arr_2: %d\n", arr_2[i]);
	}
	ft_sort_int_tab(arr_3, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("arr_3: %d\n", arr_3[i]);
	}
	ft_sort_int_tab(arr_4, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("arr_4: %d\n", arr_4[i]);
	}
	return (0);
} */