/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:58:37 by dayou             #+#    #+#             */
/*   Updated: 2023/02/20 20:00:27 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

/* #include <stdio.h>
int	main(void)
{
	char	arr[];
	char	*prt;

	arr[] = "3 2 1 2 1 2 2 3 3 2 2 1 2 1 2 3";
	prt = "a!";
	printf("arr: %d\n", ft_strlen(arr));
	printf("arr: %d\n", ft_strlen(prt));
	return (0);
} */
