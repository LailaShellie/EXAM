#include <unistd.h>

int main(int argc, char **argv)
{
	char *s;
	int i;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	s = argv[1];
	while (s[i])
		++i;
	while (--i >= 0)
		write(1, &s[i], 1);
	return (0);
}