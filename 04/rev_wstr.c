#include <unistd.h>

void print_w(char *s)
{
	while (*s && *s != ' ')
	{
		write(1, s, 1);
		++s;
	}
}

int main(int argc, char **argv)
{
	char *s;
	int i;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	s = argv[1];
	while (s[i])
		++i;
	while (0 <= i)
	{
		if (s[i] != ' ' && s[i - 1] == ' ')
		{
			print_w(&s[i]);
			write(1, " ", 1);
		}
		if (s[i] != ' ' && i == 0)
			print_w(&s[i]);
		--i;
	}
	write(1, "\n", 1);
	return (0);
}
