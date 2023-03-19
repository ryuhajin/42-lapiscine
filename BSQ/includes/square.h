/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 01:29:42 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/01 23:15:29 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

typedef struct s_square
{
	int	i;
	int	j;
	int	len;
}	t_square;

t_square	*find_square(int **map, int width, int height);

#endif
