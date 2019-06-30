#include <unistd.h>

void print_line(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		++s;
	}
}

void solve(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	while (s2[j] && s1[i])
	{
		if (s1[i] == s2[j])
			++i;
		++j;
	}
	if (s1[i] == 0)
		print_line(s1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		solve(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}