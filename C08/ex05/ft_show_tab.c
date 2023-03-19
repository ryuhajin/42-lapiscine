/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:35:27 by dayou             #+#    #+#             */
/*   Updated: 2023/03/01 17:16:40 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &(str[idx]), 1);
		idx++;
	}
}

void	ft_putnbr(int size)
{
	int		len;
	char	*numbers;

	len = size;
	numbers = "0123456789";
	if (len < 10)
	{
		write(1, &numbers[len % 10], 1);
	}
	else
	{
		ft_putnbr(len / 10);
		write(1, &numbers[len % 10], 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		write(1, "\n", 1);
		par++;
	}
}
