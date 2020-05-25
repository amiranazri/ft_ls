#include "ft_ls.h"

void ft_sort(t_list *tmp)
{
    t_list  *start;
    char    *cont;

    start = (t_list *)ft_memalloc(sizeof(t_list));

    start = tmp;

    while (tmp->next != NULL)
    {

        if (tmp->data_name == NULL)
        {
            tmp = tmp->next;
            continue ;
        }
       
        if (ft_strcmp(tmp->data_name, tmp->next->data_name) > 0)
        {
            cont = tmp->data_name;
			tmp->data_name = tmp->next->data_name;
			tmp->next->data_name = cont;
			tmp = start;
        }
        else 
            tmp = tmp->next; 
    }
	tmp->next = NULL;
	tmp = start;
}