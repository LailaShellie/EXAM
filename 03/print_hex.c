#include <stdio.h>
#include <stdlib.h>

void		ft_print(unsigned int c)
{
	char	nbr;

	nbr = 0;
	if (c <= 9)
		nbr = c + 48;
	else if (c >= 10 && c <= 15)
		nbr = c + 55;
	printf("%c", nbr);
}

void		print_hex(unsigned int nbr)
{
	if (nbr > 15)
	{
		print_hex(nbr / 16);
		ft_print(nbr % 16);
		return ;
	}
	ft_print(nbr);
}

int		main(int argc, char **argv)
{
	(void)argc;
	print_hex(atoi(argv[1]));
	return (0);
}