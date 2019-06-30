#include <stdlib.h>
#include <stdio.h>

int		ascending(int a, int b)
{
	return (a <= b);
}

typedef struct    s_list
{
	struct s_list *next;
	void          *data;
}                 t_list;

int		get_list_len(t_list *list)
{
	int len;

	len = 0;
	while (list)
	{
		++len;
		list = list->next;
	}
	return (len);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *first;
	t_list *cur;
	void *tmp;
	int size;
	int i;
	if (!cmp && !lst)
		return (lst);
	i = 0;
	first = lst;
	size = get_list_len(lst);
	while (i < size)
	{
		cur = first;
		while (cur->next)
		{
			if (!cmp((int)cur->data, (int)cur->next->data))
			{
				tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
		}
		++i;
	}
	return (first);
}

int		main(void)
{
	t_list *l;
	int		i;
	t_list	*t;
	t_list	*b;

	i = 50;
	l = malloc(sizeof(t_list));
	t = l;
	b = l;
	while (i)
	{
		l->data = i % 3;
		l->next = malloc(sizeof(t_list));
		l = l->next;
		--i;
	}
	l->data = 0;
	l->next = NULL;
	while (t)
	{
		printf("%d ", (int)t->data);
		t = t->next;
		++i;
	}
	b = sort_list(b, ascending);
	printf("\n");
	while (b)
	{
		printf("%d ", (int)b->data);
		b = b->next;
		++i;
	}
}