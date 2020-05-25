#include "ft_ls.h"

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
            str = tmp->fileName;
			tmp->fileName = tmp->fw->fileName;
			tmp->fw->fileName = str;
			tmp = head;
        }
        else 
            tmp = tmp->next; 
    }
}

void	sortAscii(t_ls *tmp)
{
	t_ls		*head;
	char		*str;

	head = (t_ls *)malloc(sizeof(t_ls));
	head = tmp;
	while (tmp->fw != NULL)
	{
		if (tmp->fileName == NULL)
			tmp = tmp->fw;
		if (ft_strcmp(tmp->fileName, tmp->fw->fileName) > 0)
		{
			str = tmp->fileName;
			tmp->fileName = tmp->fw->fileName;
			tmp->fw->fileName = str;
			tmp = head;
		}
		else
			tmp = tmp->fw;
	}
	tmp->fw = NULL;
	tmp = head;
}