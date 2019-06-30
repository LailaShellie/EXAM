#include <stdlib.h>
#include <stdio.h>

int		get_num_len(int nbr)
{
	int sign;
	int len;

	len = 0;
	sign = 0;
	if (nbr <= 0)
		sign = 1;
	while (nbr)
	{
		++len;
		nbr /= 10;
	}
	return (len + sign);
}

char	*ft_itoa(int nbr)
{
	int len;
	char *s;
	int k = 0;

	len = get_num_len(nbr);
	if (!(s = (char *)malloc(len + 1)))
		return (0);
	if (nbr < 0)
	{
		nbr = -nbr;
		s[0] = '-';
		k = 1;
	}
	s[len--] = 0;
	while (len >= k)
	{
		s[len] = nbr % 10 + '0';
		nbr /= 10;
		--len;
	}
	return (s);
}

int main()
{
	printf("%s\n",ft_itoa(-1203400));
	return (0);
}