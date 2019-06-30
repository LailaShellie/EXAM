#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int a)
{
	char c;

	if (a < 10)
	{
		c = a + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
}

int ft_atoi(char *s)
{
	int res = 0;

	if (*s == '-')
		return (-1);
	while (*s)
	{
		res = res * 10 + (*s - '0');
		++s;
	}
	return (res);
}

void ft_eratosphen(int a)
{
	int tab[10000] = {0};
	tab[0] = 1;
	tab[1] = 1;
	int i = 2;
	int j = 1;
	while (i <= a)
	{
		if (tab[i] == 0)
		{
			while (j * i <= a)
			{
				++j;
				tab[i * j] = 1;
			}
			j = 1;
		}
		++i;
	}
	i = 0;
	int res = 0;
	while (i <= a)
	{
		if (tab[i] == 0)
			res += i;
			++i;
	}
	ft_putnbr(res);
}

int main(int argc, char **argv)
{
	int a;

	if (argc == 2)
	{
		a = ft_atoi(argv[1]);
		if (a < 0 || a == 0)
		{
			write(1, "0\n", 2);
			return (0);
		}
		ft_eratosphen(a);
		return (0);
	}
	write(1, "0\n", 2);
	return (0);
}
