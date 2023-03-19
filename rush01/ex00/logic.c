/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:41:28 by yenoh             #+#    #+#             */
/*   Updated: 2023/02/19 13:03:47 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_board(int board[][4]);
void	init_cases(int cases[][4]);
int		check_board(int board[][4], int input[][2], int cases[][4]);

int	recursive(int cases[][4], int board[][4], int depth, int input[][2])
{
	int	i;
	int	j;

	if (depth >= 4)
	{
		if (check_board(board, input, cases))
		{
			print_board(board);
			return (1);
		}
		return (0);
	}
	i = 0;
	while (i < 24)
	{
		j = -1;
		while (++j < 4)
			board[depth][j] = cases[i][j];
		if (recursive(cases, board, depth + 1, input))
			return (1);
		i++;
	}
	return (0);
}

int	logic(int input[][2])
{
	int	board[4][4];
	int	cases[24][4];

	init_cases(cases);
	return (recursive(cases, board, 0, input));
}
