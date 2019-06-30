#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2048

int			main(int argc, const char *argv[])
{
	int		i;
	int		loop;
	char	*arr;
	int		j = 0;
	char	*cur_sym;

	if (argc == 2)
	{
		i = 0;
		cur_sym = (char *)argv[1];
		if (!(arr = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
		while (i <= BUFF_SIZE)
			arr[i++] = '\0';
		i = 0;
		while (cur_sym[i])
		{
			cur_sym[i] == '<' ? j -= 1 : j;
			cur_sym[i] == '>' ? j += 1 : j;
			cur_sym[i] == '+' ? arr[j] += 1 : arr[j];
			cur_sym[i] == '-' ? arr[j] -= 1 : arr[j];
			if (cur_sym[i] == '.')
				write(1, &arr[j], 1);
			if (cur_sym[i] == '[' && !arr[j])
			{
				loop = 1;
				while (loop)
				{
					++i;
					cur_sym[i] == '[' ? loop += 1 : loop;
					cur_sym[i] == ']' ? loop -= 1 : loop;
				}
			}
			if (cur_sym[i] == ']' && arr[j])
			{
				loop = 1;
				while (loop)
				{
					--i;
					cur_sym[i] == '[' ? loop -= 1 : loop;
					cur_sym[i] == ']' ? loop += 1 : loop;
				}
			}
			i += 1;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
