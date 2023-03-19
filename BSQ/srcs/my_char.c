/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:36:26 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 02:30:21 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	is_white_space(char c)
{
	if (c == ' ' || ('\t' <= c && c <= '\r'))
		return (1);
	return (0);
}

int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	is_printable(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}
