#include "ft_ls.h"

void ft_sort(t_list *tmp)
{
    t_list  *start;
    char    *cont;

    start = tmp;

    while (tmp->next != NULL)
    {
        if (tmp == NULL)
        {
            tmp = tmp->next;
        }
       
        if (ft_strcmp(tmp->data_name, tmp->next->data_name) > 0)
        {
            //swap values around
            cont = tmp->data_name;
            tmp->data_name = tmp->next->data_name;
            tmp->next->data_name = cont;
        }
        else 
            tmp = tmp->next; 
    }
}