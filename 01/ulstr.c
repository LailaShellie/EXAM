#include <unistd.h>

int is_alpha(char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c -=  32;
		return (1);
	}
	else if (*c > 'A' && *c <= 'Z')
	{
		*c += 32;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *s = argv[1];
	while (*s)
	{
		is_alpha(s);
		write(1, s, 1);
		++s;
	}
	write(1, "\n", 1);
	return (0);
}