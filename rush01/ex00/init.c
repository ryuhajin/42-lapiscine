/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:38:05 by yenoh             #+#    #+#             */
/*   Updated: 2023/02/19 12:03:28 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_cases(int cases[][4], int visit[4], int *row_p, int col)
{
	int	i;

	if (col >= 4)
	{
		(*row_p)++;
		i = -1;
		if (*row_p < 24)
		{
			while (++i < 4)
				cases[*row_p][i] = cases [(*row_p) - 1][i];
		}
		return ;
	}
	i = 0;
	while (i < 4)
	{
		if (!visit[i])
		{
			cases[*row_p][col] = i + 1;
			visit[i] = 1;
			set_cases(cases, visit, row_p, col + 1);
			visit[i] = 0;
		}
		i++;
	}
}

void	ft_memcpy(int val[2], int a, int b)
{
	val[0] = a;
	val[1] = b;
}

void	init_values(int vals[][2])
{
	ft_memcpy(vals[0], 4, 1);
	ft_memcpy(vals[1], 3, 2);
	ft_memcpy(vals[2], 3, 1);
	ft_memcpy(vals[3], 3, 2);
	ft_memcpy(vals[4], 2, 2);
	ft_memcpy(vals[5], 2, 3);
	ft_memcpy(vals[6], 3, 1);
	ft_memcpy(vals[7], 2, 2);
	ft_memcpy(vals[8], 3, 1);
	ft_memcpy(vals[9], 3, 2);
	ft_memcpy(vals[10], 2, 2);
	ft_memcpy(vals[11], 2, 3);
	ft_memcpy(vals[12], 2, 1);
	ft_memcpy(vals[13], 2, 2);
	ft_memcpy(vals[14], 2, 1);
	ft_memcpy(vals[15], 2, 2);
	ft_memcpy(vals[16], 2, 2);
	ft_memcpy(vals[17], 2, 3);
	ft_memcpy(vals[18], 1, 2);
	ft_memcpy(vals[19], 1, 3);
	ft_memcpy(vals[20], 1, 2);
	ft_memcpy(vals[21], 1, 3);
	ft_memcpy(vals[22], 1, 3);
	ft_memcpy(vals[23], 1, 4);
}

void	init_cases(int cases[][4])
{
	int	row;
	int	visit[4];
	int	i;

	i = 0;
	while (i < 4)
		visit[i++] = 0;
	row = 0;
	set_cases(cases, visit, &row, 0);
}
