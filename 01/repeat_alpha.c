#include <unistd.h>

int is_alpha(char c, int *a)
{
	if (c >= 'a' && c <= 'z')
	{
		*a = c - 96;
		return (1);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		*a = c - 64;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	char *s;
	int num;

	num = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	s = argv[1];
	while (*s)
	{
		if (is_alpha(*s, &num))
			while (num)
			{
				write(1 , s, 1);
				--num;
			}
		++s;
	}
	write(1, "\n", 1);
	return (0);
}