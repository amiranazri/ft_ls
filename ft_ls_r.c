#include "ft_ls.h"

void    ft_ls_r(const char *itm)
{
	char		*container;
	t_list		*data;
	t_list		*tmp;


	itm = data->next->data_name;
	tmp = data;
	while (data->next)
	{
		if ((ft_strcmp(data->next->data_name, data->data_name)) > 0)
		{
			container = data->data_name;
			data->data_name = data->next->data_name;
			data->next->data_name = container;
			data = tmp;
		}
		else
			data = data->next;
	}
	data->next = NULL;
	data = tmp;
}