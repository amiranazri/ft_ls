#include "ft_ls.h"

t_list *add_node(t_list *head, char *file_name, char *mtime) 
{ 
    t_list *tmp;

    tmp = head;
    if (head == NULL)
    {
        tmp = (t_list *)malloc(sizeof(t_list));
        if(mtime[0] != '0')
            tmp->data_name = ft_strdup(ft_strjoin(mtime, file_name));
        else
            tmp->data_name = ft_strdup(file_name);
        tmp->next = head;
        head = tmp;
    }
    else 
    {
       insert_node(file_name, tmp, mtime);
       //pass head the new node address
       head = tmp;
    }
    return (head);
}