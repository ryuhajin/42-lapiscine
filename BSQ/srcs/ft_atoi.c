/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:40:48 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 12:20:56 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_char.h"

int	ft_atoi(char *input)
{
	int	sign;
	int	num;
	int	idx;

	idx = 0;
	while (is_white_space(input[idx]))
		idx++;
	sign = 1;
	if (is_sign(input[idx]))
	{
		if (input[idx] == '-')
			sign = -1;
		idx++;
	}
	num = 0;
	while (is_num(input[idx]))
	{
		num = (num * 10) + (input[idx] - '0');
		idx++;
	}
	return (num * sign);
}
