/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjucho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:44:42 by wonjucho          #+#    #+#             */
/*   Updated: 2023/02/15 14:20:51 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

void	rush(int a, int b);

int	main(int argc, char* argv[])
{
	if(argc == 3)
		rush(atoi(argv[1]), atoi(argv[2]));
	return (0);
}
