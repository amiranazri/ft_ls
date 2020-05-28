#include "ft_ls.h"
#include <stdio.h>

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
    deleteAllNodes(start);
}

void ft_reverse_sort(t_list *tmp)
{
    t_list  *start;
    char    *cont;

    start = (t_list *)malloc(sizeof(t_list));

    start = tmp;

    while (tmp->next != NULL)
    {
        if (tmp->data_name == NULL)
        {
            tmp = tmp->next;
            continue ;
        }

        if (ft_strcmp(tmp->data_name, tmp->next->data_name) < 0)
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

void ft_time_sort(t_list *tmp)
{
    struct stat status1;
    struct stat status2;
    t_list  *start;
    char    *cont;

    start = (t_list *)malloc(sizeof(t_list));
    start = tmp;
    while (tmp->next != NULL)
    {
        stat(tmp->data_name, &status1);
        stat(tmp->next->data_name, &status2);
       
        if (((status1.st_mtime) < (status2.st_mtime)))
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