#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			++j;
		}
		++i;
	}
}

int		main(void)
{
	int a[7] = {9, 7, 6, 4, 5, 10, 1};
	int i = 0;
	int size = 7;

	sort_int_tab(a, size);
	while (i < size)
	{
		printf("%d ", a[i]);
		++i;
	}
	return (0);
}
