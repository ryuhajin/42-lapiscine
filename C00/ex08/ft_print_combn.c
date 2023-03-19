/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:05:15 by dayou             #+#    #+#             */
/*   Updated: 2023/02/15 20:00:03 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combn(int n, int level, int i, char *arr)
{
	if (level == n)
	{
		write(1, arr, n);
		if (arr[0] != 10 - n + '0')
			write(1, ", ", 2);
		return ;
	}
	while (i <= 9)
	{
		arr[level] = i + '0';
		print_combn(n, level + 1, i + 1, arr);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		level;
	int		i;
	char	arr[11];

	level = 0;
	i = 0;
	print_combn(n, level, i, arr);
}

/* int	main(void)
{
	ft_print_combn(3);
	return (0);
} */