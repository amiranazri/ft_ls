#include "ft_ls.h"

void    ft_print_list(t_list *head)
{
    t_list	*tmp;

    tmp = head;
    while(tmp != NULL)
    {
        ft_putendl(tmp->data_name);
        tmp = tmp->next;
    }
}