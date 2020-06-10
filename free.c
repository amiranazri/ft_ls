#include "ft_ls.h"

void    free_list(t_list    *list)
{
    t_list  *tmp;
    tmp = list;
    while(tmp != NULL) 
    {
        tmp = tmp->next;
        free (list);
        list = tmp;
    }
}
