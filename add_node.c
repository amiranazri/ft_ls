#include "ft_ls.h"

// void    add_node(t_list **head, char *file_name)
// {
//     t_list node;

//     if (*head == NULL)
//     {
//         node = (t_list *)malloc(sizeof(t_list));
//         *head->data_name = file_name;
//     }
// }

void add_node(t_list **head, char *file_name) 
{ 
    /* 1. allocate node */
    t_list *new_node;
    if(*head == NULL)
    {
        *head = (t_list *)malloc(sizeof(t_list));
    }
    new_node = (t_list *)malloc(sizeof(t_list)); 
    new_node->data_name = (char *)malloc(sizeof(char));
    /* 2. put in the data  */
    new_node->data_name = file_name; 
    /* 3. Make next of new node as head */
    new_node->next = *head; 
    /* 4. move the head to point to the new node */
    *head = new_node;
}