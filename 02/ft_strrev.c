#include <stdio.h>

char    *ft_strrev(char *str)
{
	int i;
	int j;
	char tmp;

	j = 0;
	i = 0;
	while (str[i])
		++i;
	--i;
	while (j < i)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		++j;
		--i;
	}
	return (str);
}
