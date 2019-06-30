#include <unistd.h>

int main()
{
	char c;
	int i;

	i = 1;
	c = 'z';
	while (c != 'a' - 1)
	{
		if (i & 1)
			write(1, &c, 1);
		else
		{
			c = c - 32;
			write(1, &c, 1);
			c = c + 32;
		}
		++i;
		--c;
	}
	write(1, "\n", 1);
	return (0);
}