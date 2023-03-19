/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:50:56 by yenoh             #+#    #+#             */
/*   Updated: 2023/02/19 23:08:10 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_pattern_id(int *arr, int cases[][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[j] != cases[i][j])
				break ;
			if (j == 3)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	check_rule_col(int board[][4], int input[][2], \
					int cases[][4], int vals[][2])
{
	int	i;
	int	j;
	int	arr[4];
	int	id;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr[j] = board[j][i];
			j++;
		}
		id = get_pattern_id(arr, cases);
		if (id == -1 || vals[id][0] != input[i][0] || \
			vals[id][1] != input[i][1])
			return (0);
		i++;
	}
	return (1);
}

int	check_rule_row(int board[][4], int input[][2], \
					int cases[][4], int vals[][2])
{
	int	i;
	int	j;
	int	arr[4];
	int	id;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr[j] = board[i][j];
			j++;
		}
		id = get_pattern_id(arr, cases);
		if (id == -1 || vals[id][0] != input[4 + i][0] || \
			vals[id][1] != input[4 + i][1])
			return (0);
		i++;
	}
	return (1);
}

int	check_rule(int board[][4], int input[][2], int cases[][4], int vals[][2])
{
	if (!check_rule_col(board, input, cases, vals))
		return (0);
	if (!check_rule_row(board, input, cases, vals))
		return (0);
	return (1);
}
