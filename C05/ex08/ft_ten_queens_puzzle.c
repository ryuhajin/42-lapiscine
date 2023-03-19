/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:23:06 by dayou             #+#    #+#             */
/*   Updated: 2023/02/24 20:03:33 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	queens_check(char *chess_board, int y)
{
	int	i;
	int	dig_check[2];

	i = 0;
	while (i < y)
	{
		if (chess_board[i] == chess_board[y])
			return (0);
		dig_check[0] = chess_board[i] - chess_board[y];
		dig_check[1] = i - y;
		if (dig_check[0] < 0)
			dig_check[0] *= -1;
		if (dig_check[1] < 0)
			dig_check[1] *= -1;
		if (dig_check[0] == dig_check[1])
			return (0);
		i++;
	}
	return (1);
}

void	print_chess_board(char *chess_board)
{
	int	idx;

	idx = 0;
	while (idx < 10)
	{
		write(1, &(chess_board[idx]), 1);
		idx++;
	}
	write(1, "\n", 1);
}

void	ten_queens(char *chess_board, int y, int *cnt)
{
	int	x;

	if (y == 10)
	{
		print_chess_board(chess_board);
		*cnt = *cnt + 1;
		return ;
	}
	x = 0;
	while (x < 10)
	{
		chess_board[y] = x + '0';
		if (queens_check(chess_board, y))
			ten_queens(chess_board, y + 1, cnt);
		x++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	chess_board[10];
	int		cnt;
	int		i;

	i = -1;
	cnt = 0;
	while (++i < 10)
	{
		chess_board[i] = -1;
	}
	i = 0;
	ten_queens(chess_board, 0, &cnt);
	return (cnt);
}
