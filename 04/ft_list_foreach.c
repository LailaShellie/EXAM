#include <stdlib.h>
typedef struct    s_list
{
	struct s_list *next;
	void          *data;
}                 t_list;

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *ptr;
	if (begin_list == 0)
		return ;
	ptr = begin_list;
	while (ptr)
	{
		f(ptr->data);
		ptr = ptr->next;
	}
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *prev;
	if (!begin_list || !*begin_list)
		return ;
	if (!cmp(data_ref, (*begin_list)->data))
	{
		prev = (*begin_list)->next;
		free(*begin_list);
		*begin_list = prev;
	}
	while (*begin_list)
	{
		if (!cmp(data_ref, (*begin_list)->data))
		{
			prev->next = (*begin_list)->next;
			free((*begin_list)->data);
			free((*begin_list));
		}
		prev = (*begin_list);
		(*begin_list) = (*begin_list)->next;
	}
}