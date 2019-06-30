#include <stdio.h>

typedef struct    s_list
{
	struct s_list *next;
	void          *data;
}                 t_list;

int ft_list_size(t_list *begin_list)
{
	int i = 0;

	if (!begin_list)
		return (0);
	while (begin_list)
	{
		++i;
		begin_list = begin_list->next;
	}
	return (i);
}

int main()
{
	t_list list;
	t_list list1;
	list.next = &list1;
	t_list list2;
	t_list list3;
	t_list list4;
	list2.next = &list3;
	list3.next = &list4;
	list4.next = 0;
	printf("%d\n", ft_list_size(&list));
}