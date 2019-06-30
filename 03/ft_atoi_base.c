#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(const char c)
{
	int	nbr;

	nbr = 0;
	if (c >= '0' && c <= '9')
		nbr = c - 48;
	else if (c >= 'A' && c <= 'F')
		nbr = c - 55;
	else if (c >= 'a' && c <= 'f')
		nbr = c - 87;
	return (nbr);
}

int		ft_pow(int a, int b)
{
	int		res;

	res = 1;
	while (b)
	{
		if (b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return (res);
}

int		ft_atoi_base(const char *str, unsigned int base)
{
	int len = 0;
	int a[1000];
	int res;

	res = 0;
	while (str[len])
	{
		a[len] = ft_atoi(str[len]);
		++len;
	}
	int i = 0;
	while (--len >= 0)
	{
		res += ft_pow(base, i) * a[len];
		++i;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
	return (0);
}
