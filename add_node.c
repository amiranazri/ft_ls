#include "ft_ls.h"

t_list *add_node(t_list *head, char *file_name) 
{ 
    t_list *tmp;

    tmp = head;
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
    return (head);
}