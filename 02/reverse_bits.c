#include <unistd.h>
#include <stdlib.h>

void	print_bits(unsigned char octet)
{
	int i = 7;
	while (i != -1)
	{
		if (octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		--i;
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char tmp = 1;
	unsigned char res = 0;
	int i = 0;
	int j = 7;

	print_bits(octet);
	write(1, "\n", 1);
	while (i < 8)
	{
		if (octet & (tmp << i))
			res ^= 1 << j;
		--j;
		++i;
	}
	print_bits(res);
	return (res);
}

int main(int argc, char **argv)
{
    (void)argc;
    reverse_bits(atoi(argv[1]));
    return (0);
}