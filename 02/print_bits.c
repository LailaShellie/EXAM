#include <unistd.h>
#include <stdio.h>

void	print_bits(int octet)
{
	int i = 31;
	int j = 0;
	while (i >= 0)
	{
		if (octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		++j;
		if (j == 1 || j == 9)
			write(1, "|", 1);
		--i;
	}
}

int main()
{
	float a = 1.15625;
	int *b;
	b = (int *)&a;
	print_bits(*b);
	return (0);
}
