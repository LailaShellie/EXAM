#include <unistd.h>

void ft_put_word(char *s)
{
	while (*s && *s != ' ' && *s != '\t')
	{
		write(1, s, 1);
		++s;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				ft_put_word(&argv[1][i]);
				return (0);
			}
			++i;
		}
	}
	write(1, "\n", 1);
	return (0);
}