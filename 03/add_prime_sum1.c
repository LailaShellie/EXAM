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

int is_prime(int nbr)
{
	int end;
	int i = 2;

	end = nbr / 2;
	while (i <= end)
	{
		if (nbr % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int a;
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	a = ft_atoi(argv[1]);
	if (a < 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	int i = 2;
	int res = 0;
	while (i <= a)
	{
		if (is_prime(i))
			res += i;
		++i;
	}
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}