#include "ft_ls.h"

void    insert_node(char *file_name, t_list *node)
{
    t_list  *head;

    head = node;
    //because i need to foooking iterate through to the last node.
    while(head->next != NULL)
    {
        head = head -> next;
    }
    head->next = (t_list *)malloc(sizeof(t_list));
    head->next->data_name = ft_strdup(file_name);
    node = head;
    head->next->next = NULL;
    free_list(head);
}