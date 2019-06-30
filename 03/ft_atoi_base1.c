#include <stdio.h>
#include <stdlib.h>

int ft_is_space(char c)
{
	return (!(c != '\t' && c != '\v' && c != '\n' && \
		c != ' ' && c != '\r' && c != '\f'));
}

int is_in_base(char c, int base)
{
	if (base < 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) || \
	(c >= 'a' && c <= ('a' + base - 10)));
}

int	ft_atoi_base(const char *str, int base)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while (ft_is_space(str[i]))
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	while (str[i] && is_in_base(str[i], base))
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * base) + (str[i] - '0');
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = (res * base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = (res * base) + (str[i] - 'a' + 10);
		++i;
	}
	return (res * sign);
}

int		main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
	return (0);
}