#include "ft_ls.h"

void ft_ls(char *tmp)
{
	t_list	data;
	t_list	*list;

	data.directory = opendir(tmp);
	list = NULL;
	while ((data.file = readdir(data.directory)) != NULL)
	{
		if (data.file->d_name[0] == '.')
			continue;
		list = add_node(list, data.file->d_name);
	}
	ft_sort(list);
	ft_print_list(list);
	free_list(list);
	closedir(data.directory);
}