#include <unistd.h>

void	ft_print(char first, char last, int a, int line)
{
	int		i;
	char	middle;
	char	space;

	i = 0;
	middle = 'B';
	space = ' ';
	if (line == 1)
		while (i < a)
		{
			if (i == 0)
				write(1, &first, 1);
			else if (i == a - 1)
				write(1, &last, 1);
			else
				write(1, &middle, 1);
			i++;
		}
	else if (line == 0)
		while (i < a)
		{
			if (i == 0)
				write(1, &middle, 1);
			else if (i == a - 1)
				write(1, &middle, 1);
			else
				write(1, &space, 1);
			i++;
		}
	write(1, "\n", 1);
}

void	line_check(char first, char last, int a, int b)
{
	int	line;

	line = 0;
	while (line < b)
	{
		if (line == 0 || line == b - 1)
			ft_print(first, last, a, 1);
		else
			ft_print(first, last, a, 0);
		line++;
	}
}

void	rush(int a, int b)
{
	char	first_print;
	char	last_print;
	int		idx;
	int		line;

	line = 0;
	idx = 0;
	first_print = 'A';
	last_print = 'C';
	line_check(first_print, last_print, a, b);
}

int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 5;
	rush(5, 5);
	return (0);
}
