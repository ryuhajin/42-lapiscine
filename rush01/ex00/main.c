/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenoh <yenoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 09:35:00 by yenoh             #+#    #+#             */
/*   Updated: 2023/02/19 13:42:39 by yenoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		logic(int input[][2]);
void	print_error(void);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	convert_input(int input[16], char *str)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	if (ft_strlen(str) != 31)
		return (0);
	i = 1;
	while (i < 31)
	{
		if (str[i] != ' ')
			return (0);
		i += 2;
	}
	i = 0;
	while (i < 31)
	{
		if (str[i] < '1' || str[i] > '4')
			return (0);
		input[cnt++] = str[i] - '0';
		i += 2;
	}
	return (1);
}

void	set_input(int input2[][2], int input[16])
{
	input2[0][0] = input[0];
	input2[0][1] = input[4];
	input2[1][0] = input[1];
	input2[1][1] = input[5];
	input2[2][0] = input[2];
	input2[2][1] = input[6];
	input2[3][0] = input[3];
	input2[3][1] = input[7];
	input2[4][0] = input[8];
	input2[4][1] = input[12];
	input2[5][0] = input[9];
	input2[5][1] = input[13];
	input2[6][0] = input[10];
	input2[6][1] = input[14];
	input2[7][0] = input[11];
	input2[7][1] = input[15];
}

int	main(int ac, char **av)
{
	int	input[16];
	int	input2[8][2];

	if (ac == 2)
	{
		if (convert_input(input, av[1]))
		{
			set_input(input2, input);
			if (!logic(input2))
				print_error();
		}
		else
			print_error();
	}
	else
		print_error();
	return (0);
}
