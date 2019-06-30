#include <unistd.h>

int is_alpha(char *c)
{
	if (*c >= 'a' && *c < 'z')
	{
		*c += 1;
		return (1);
	}
	else if (*c == 'z')
	{
		*c = 'a';
		return (1);
	}
	else if (*c >= 'A' && *c < 'Z')
	{
		*c += 1;
		return (1);
	}
	else if (*c == 'Z')
	{
		*c = 'A';
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	char *s;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	s = argv[1];
	while (*s)
	{
		is_alpha(s);
		write(1, s, 1);
		++s;
	}
	write(1, "\n", 1);
	return (0);
}