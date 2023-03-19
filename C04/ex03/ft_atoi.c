/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:10:03 by dayou             #+#    #+#             */
/*   Updated: 2023/02/21 17:33:20 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	n_p_check;
	int	numbers;

	n_p_check = 1;
	numbers = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n_p_check *= -1;
		str++;
	}
	while ('0' <= *str && '9' >= *str)
	{
		numbers *= 10;
		numbers += *str - '0';
		str++;
	}
	numbers *= n_p_check;
	return (numbers);
}
