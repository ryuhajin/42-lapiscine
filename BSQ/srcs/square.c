/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:01:33 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 02:15:41 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

void	set_square(t_square *square, int i, int j, int len)
{
	square->i = i;
	square->j = j;
	square->len = len;
}
