#include "ft_ls.h"

t_list *new_node(char *file_name)
{
    t_list  *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data_name = ft_strdup(file_name);
    new_node->next = NULL;
    return (new_node);
}