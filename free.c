#include "ft_ls.h"

t_list *free_list(t_list *head) 
{ 
    t_list *tmp;
    char *file_name;

    tmp = head;
    while (head != NULL)
    {
        if (head == NULL)
        {
            tmp = (t_list *)malloc(sizeof(t_list));
            tmp->data_name = ft_strdup(file_name);
            tmp->next = head;
            head = tmp;
        }
        else
        {
            insert_node(file_name, tmp);
            //pass head the new node address
            head = tmp;
        }
    }
    return (head);
}