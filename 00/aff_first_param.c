#include <unistd.h>

void ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		++s;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
