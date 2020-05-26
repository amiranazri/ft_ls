#include "ft_ls.h"

void add_node(t_list *head, char *file_name) 
{ 
    t_list *node;
    t_list *tmp;

    tmp = head;
    if(head == NULL)
        exit(1) ;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    node = (t_list *)malloc(sizeof(t_list));
    node->data_name = ft_strdup(file_name);
    // tmp->next = node;
    /* 3. Make next of new node as head */
    node->next = NULL;
    /* 4. move the head to point to the new node */
    tmp = head;  
}