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
	int k;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	s = argv[1];
	i = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\t')
		++i;
	k = i;
	while (s[++i])
	{
		if ((s[i] != ' ' && s[i] != '\t') && (s[i - 1] == ' ' || s[i - 1] == '\t'))
		{
			print_w(&s[i]);
			write(1, " ", 1);
		}
	}
	print_w(&s[k]);
	write(1, "\n", 1);
	return (0);
}