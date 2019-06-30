#include <stdio.h>

unsigned int gcd(unsigned int a,unsigned  int b)
{
	if (b == 0)
		return (a);
	return (gcd(b, a % b));
}

unsigned int lcm(unsigned int a, unsigned int b)
{
	if (!a && !b)
		return (0);
	return ((a * b) / gcd(a, b));
}

unsigned int	lcm1(unsigned int a, unsigned int b)
{
	int		gcd;
	int		old_a;
	int		old_b;

	gcd = 0;
	old_a = a;
	old_b = b;
	while (1)
	{
		if (a == 0)
			break ;
		b %= a;
		if (b == 0)
			break ;
		a %= b;
	}
	gcd = (!b) ? a : b;
	return (gcd ? (old_a / gcd * old_b) : 0);
}

int main()
{
	printf("%d\n",lcm(42, 3));
	printf("%d\n",lcm1(42, 3));
	return (0);
}