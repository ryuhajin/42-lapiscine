/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:15:24 by dayou             #+#    #+#             */
/*   Updated: 2023/02/27 23:16:03 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	hex_print(unsigned long long addr)
{
	char	*hex;
	char	hex_print[16];
	int		idx;

	idx = 15;
	hex = "0123456789abcdef";
	while (idx > -1 && addr > 0)
	{
		hex_print[idx] = hex[addr % 16];
		addr /= 16;
		idx--;
	}
	while (idx > -1)
	{
		hex_print[idx] = hex[0];
		idx--;
	}
	write(1, hex_print, 16);
	write(1, ":", 1);
}

void	str_hex_print(unsigned char *addr, unsigned int idx)
{
	unsigned int	i;
	char			*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (i < 16 && i < idx)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, &hex[addr[i] / 16], 1);
		write(1, &hex[addr[i] % 16], 1);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
}

void	str_print(unsigned char *addr, unsigned int idx)
{
	unsigned int	i;

	i = 0;
	write(1, " ", 1);
	while (i < 16 && i < idx)
	{
		if (' ' <= *(addr + i) && '~' >= *(addr + i))
			write(1, addr + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long	addr_;
	unsigned int		i;
	unsigned int		idx;

	i = 0;
	idx = 0;
	addr_ = (unsigned long long)addr;
	while (i < size)
	{
		idx = size - i;
		hex_print(addr_ + i);
		str_hex_print((unsigned char *)addr_ + i, idx);
		str_print((unsigned char *)addr_ + i, idx);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

int main(void)
{
	char * str = "89278923748234797234987";

	ft_print_memory(str,200);

	return 0;
}