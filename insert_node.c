#include "ft_ls.h"

void    insert_node(char *file_name, t_list *node, char *mtime)
{
    t_list  *head;

    head = node;
    while(head->next != NULL)
    {
        //iterating through to the last node.
        head = head -> next;
    }
    head->next = (t_list *)malloc(sizeof(t_list));
    if(mtime[0] != '0')
        head->next->data_name = ft_strdup(ft_strjoin(mtime, file_name));
    else
        head->next->data_name = ft_strdup(file_name);
    node = head;
    head->next->next = NULL;
}