/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjucho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:16:27 by wonjucho          #+#    #+#             */
/*   Updated: 2023/02/11 22:59:27 by wonjucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char *arr, int n);

void	first_last(int garo)
{
	int	s;

	s = 0;
	ft_putchar("o", 1);
	while (s < garo - 2)
	{
		ft_putchar("-", 1);
		s++;
	}
	ft_putchar("o\n", 2);
}

void	others(int garo)
{
	int	s;

	s = 0;
	ft_putchar("|", 1);
	while (s < garo - 2)
	{
		ft_putchar(" ", 1);
		s++;
	}
	ft_putchar("|\n", 2);
}

void	rush(int garo, int sero)
{
	int	line;

	line = 0;
	if (garo <= 0 || sero <= 0)
	{
		return ;
	}
	while (line < sero)
	{
		if (line == 0 || line == sero - 1)
		{
			first_last(garo);
		}
		else
		{
			others(garo);
		}
		line ++;
	}
}
