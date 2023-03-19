#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	first_end(int a, int b)
{
	char	circle;
	char	line;
	int		idx;

	circle = 'A';
	line = 'B';
	idx = 0;
	while (idx < a)
	{
		if (idx == 0 || idx == a - 1)
			ft_putchar(circle);
		ft_putchar(line);
		idx++;
	}
	ft_putchar(newline);
}

void	middle(int a, int b)
{
	char	area;
	char	line;
	char	newline;
	int		idx;
	int		col;

	area = ' ';
	line = 'B';
	newline = '\n';
	col = 1;
	idx = 0;
	while (col < b - 1)
	{
		while (idx < a)
		{
			if (idx == 0 || idx == a - 1)
				ft_putchar(line);
			ft_putchar(area);
			idx++;
		}
		ft_putchar(newline);
		col++;
	}
}

void	rush_00(int a, int b)
{
	int	i;

	i = 0;
	while (i < b)
	{
		if (i == 0 || i == b - 1)
			first_end(a);
		middle(a, b);
		i++;
	}
}

int	main(void)
{
	int a = 5;
	int b = 3;

	rush_00(a, b); //b가 행을 몇번 출력할지.  a는 문자를 몇개 출력할지
	return (0);
}