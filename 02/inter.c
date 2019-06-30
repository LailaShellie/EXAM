#include <unistd.h>
#include <stdio.h>

void solve(char *s1, char *s2)
{
	int i = -1;
	int tab[256] = {0};

	while (s2[++i])
	{
		if (tab[(int)s2[i]] == 0)
			tab[(int)s2[i]] = 1;
	}
	i = 0;
	while (s1[i])
	{
		if (tab[(int)s1[i]] == 1)
		{
			write(1, &s1[i], 1);
			tab[(int) s1[i]] = 2;
		}
		++i;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		solve(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}

