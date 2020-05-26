#include "ft_ls.h"

void    insert_node(char *file_name, t_list *node)
{
    t_list  *head;

    head = node;
    while(head->next != NULL)
    {
        //iterating through to the last node.
        head = head -> next;
    }
    head->next = (t_list *)malloc(sizeof(t_list));
    head->next->data_name = ft_strdup(file_name);
    node = head;
    head->next->next = NULL;
}