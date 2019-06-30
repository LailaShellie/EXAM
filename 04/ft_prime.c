#include <stdio.h>
#include <stdlib.h>

int		ft_is_prime(int nbr)
{
	int i;
	int last;

	i = 2;
	last = nbr / 2;
	while (i <= last)
	{
		if (nbr % i == 0)
			return (0);
		++i;
	}
	return (1);
}

void	ft_prime(int nbr)
{
	int i;
	int last;

	i = 2;
	if (!nbr || ft_is_prime(nbr))
	{
		printf("%d", nbr);
		return ;
	}
	last = nbr / 2;
	while (i <= last)
	{
		if (nbr % i == 0 && ft_is_prime(i))
		{

			printf("%d", i);
			printf("*");
			ft_prime(nbr / i);
			break ;
		}
		++i;
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	ft_prime(atoi(argv[1]));
	return (0);
}