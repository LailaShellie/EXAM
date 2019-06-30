#include <unistd.h>

int main(int argc, char **argv)
{
	char *s;
	if (argc != 2)
	{
		write(1, "z\n", 2);
		return (0);
	}
	s = argv[1];
	while (*s)
	{
		if (*s == 'z')
		{
			write(1, "z\n", 2);
			return (0);
		}
		++s;
	}
	write(1, "\n", 1);
	return (0);
}
