#include <unistd.h>

void print_word(char **s)
{
	while (**s != 0 && **s != ' ' && **s != '\t')
	{
		write(1 , *s, 1);
		++(*s);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *s = argv[1];
	int flag = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			++s;
		if (*s != '\t' && *s != ' ' && *s != 0)
		{
			if (flag)
				write(1, "   ", 3);
			else
				flag = 1;
			print_word(&s);
			if (!*s)
				break ;
		}
		++s;
	}
	write(1, "\n", 1);
	return (0);
}