/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjucho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:03:22 by wonjucho          #+#    #+#             */
/*   Updated: 2023/02/11 22:59:37 by wonjucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char arr[], int n);

void	first(int garo)
{
	int	s;

	s = 0;
	while (s < garo)
	{
		if (s == 0)
		{
			ft_putchar("A", 1);
		}
		else if (s == garo - 1)
		{
			ft_putchar("C", 1);
		}
		else
		{
			ft_putchar("B", 1);
		}
		s ++;
	}
}

void	last(int garo)
{
	int	s;

	s = 0;
	while (s < garo)
	{
		if (s == 0)
		{
			ft_putchar("C", 1);
		}
		else if (s == garo - 1)
		{
			ft_putchar("A", 1);
		}
		else
		{
			ft_putchar("B", 1);
		}
		s ++;
	}
}

void	the_others(int garo)
{
	int	s;

	s = 0;
	while (s < garo)
	{
		if (s == 0 || s == garo - 1)
		{
			ft_putchar("B", 1);
		}
		else
		{
			ft_putchar(" ", 1);
		}
		s ++;
	}
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
		if (line == 0)
		{
			first(garo);
		}
		else if (line == sero - 1)
		{
			last(garo);
		}
		else
		{
			the_others(garo);
		}
		ft_putchar("\n", 1);
		line++;
	}
}
