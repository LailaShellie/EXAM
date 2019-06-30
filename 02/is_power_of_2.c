#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	int i = 0;
	int num = 0;
	if (n == 0)
		return (0);
	while (i < 27)
	{
		if (n & (1 << i))
			++num;
		++i;
	}
	if (num == 1)
		return (1);
	return (0);
}
