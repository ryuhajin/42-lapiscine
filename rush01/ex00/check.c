/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:27:42 by yenoh             #+#    #+#             */
/*   Updated: 2023/02/19 13:41:09 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_values(int vals[][2]);
int		check_rule(int board[][4], int in[][2], int ca[][4], int va[][2]);
int		check_dupl(int board[][4]);

int	check_board(int board[][4], int input[][2], int cases[][4])
{
	int	vals[24][2];

	if (!check_dupl(board))
		return (0);
	init_values(vals);
	if (!check_rule(board, input, cases, vals))
		return (0);
	return (1);
}
