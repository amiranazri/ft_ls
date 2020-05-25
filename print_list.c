#include "ft_ls.h"

void    print_list(t_list *head)
{
    t_list	*tmp;

    tmp = head;
    while(tmp->next != NULL)
    {
        ft_putendl(tmp->data_name);
        tmp = tmp->next;
    }
}