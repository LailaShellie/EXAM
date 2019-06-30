#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	check_diag(char **field, int x, int y, int base)
{
	int i;
	int j;

	i = x;
	j = y;
	while (i < base && j < base)
	{
		if (field[j][i] == 'Q' || field[j][i] == 'B')
			return (1);
		++i;
		++j;
	}
	i = x;
	j = y;
	while (i > 0 && j > 0)
	{
		if (field[j][i] == 'Q' || field[j][i] == 'B')
			return (1);
		--i;
		--j;
	}
	i = x;
	j = y;
	while (i > 0 && j < base)
	{
		if (field[j][i] == 'Q' || field[j][i] == 'B')
			return (1);
		--i;
		++j;
	}
	i = x;
	j = y;
	while (i < base && i > 0)
	{
		if (field[j][i] == 'Q' || field[j][i] == 'B')
			return (1);
		++i;
		--j;
	}
	return (0);
}

int check_lines(char **field, int x, int y, int base)
{
	int line = 0;
	int column = 0;

	while (line < base)
	{
		if (field[line][x] == 'Q' || field[line][x] == 'R')
			return (1);
		++line;
	}
	column = 0;
	while (column < base)
	{
		if (field[y][column] == 'Q' || field[y][column] == 'R')
			return (1);
		++column;
	}
	return (0);
}

int		solve(char **str, int base)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (y < base)
	{
		x = 0;
		while (x < base && str[y][x] != 'K')
		{
			++x;
		}
		if (str[y][x] == 'K')
			break ;
		++y;
	}
	if (check_lines(str, x, y, base) == 1)
		return (1);
	if (check_diag(str, x, y, base) == 1)
		return (1);
	return (0);
}

char	**make_square(char **str, int base)
{
	int i;
	int j;
	char **field;

	j = 0;
	if (!(field = (char **)malloc(base * sizeof(char *))))
		return (0);
	while (j < base)
	{
		field[j] = (char *)malloc(base);
		++j;
	}
	j = 0;
	while (j < base)
	{
		i = 0;
		while (i < base)
		{
			field[j][i] = str[j][i];
			++i;
		}
		++j;
	}
	j = 0;
	while (j < base)
	{
		i = 0;
		while (i < base)
		{
			printf("%c ", field[j][i]);
			++i;
		}
		printf("\n");
		++j;
	}
	return (field);
}

int		main(int argc, char **argv)
{
	char **field;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	int base = argc - 1;
	field = make_square(argv + 1, base);
	if (solve(field, base))
		printf("Succes\n");
	else
		printf("Fail\n");
	return (0);
}