#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	char *s;

	if (argc != 2)
	{
		ft_putchar('a');
		ft_putchar('\n');
		return (0);
	}
	s = argv[1];
	while (*s)
	{
		if (*s == 'a')
		{
			ft_putchar('a');
			ft_putchar('\n');
			return (0);
		}
		++s;
	}
	ft_putchar('\n');
	return (0);
}
