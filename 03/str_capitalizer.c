#include <unistd.h>

int ft_is_space(char c)
{
	return (!(c != '\t' && c != '\v' && c != '\n' && \
		c != ' ' && c != '\r' && c != '\f'));
}

int ft_is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int ft_to_lower(char *c)
{
	if (ft_is_alpha(*c))
	{
		if (*c >= 'a' && *c <= 'z')
			return (0);
		else if (*c >= 'A' && *c <= 'Z')
		{
			*c = *c + 32;
			return (1);
		}
	}
	return (0);
}

int ft_to_upper(char *c)
{
	if (ft_is_alpha(*c))
	{
		if (*c >= 'A' && *c <= 'Z')
			return (0);
		else if (*c >= 'a' && *c <= 'z')
		{
			*c = *c - 32;
			return (1);
		}
	}
	return (0);
}

void ft_capitalize(char *s)
{
	if (ft_is_alpha(*s))
		ft_to_upper(s);
	++s;
	while (*s)
	{
		ft_to_lower(s);
		if (ft_is_alpha(*s) && ft_is_space(*(s - 1)))
			ft_to_upper(s);
		++s;
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = 1;
	int j = 0;
	while (i < argc)
	{
		ft_capitalize(argv[i]);
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			++j;
		}
		write(1, "\n", 1);
		j = 0;
		++i;
	}
	return (0);
}