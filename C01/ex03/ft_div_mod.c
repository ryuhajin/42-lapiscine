/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:47:15 by dayou             #+#    #+#             */
/*   Updated: 2023/02/20 20:00:14 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/* int	main(void)
{
	int div;
	int mod;

	div = 0;
	mod = 10;

	printf("div: %d, mod: %d\n", div, mod);
	ft_div_mod(10, 2, &div, &mod);
	printf("div: %d, mod: %d\n", div, mod);

	return (0);
} */
