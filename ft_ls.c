#include "ft_ls.h"

void ft_ls(char **tmp)
{
	t_list	data;
	t_list	*list;
	int i;

	i = 0;
	while(i < 1)
	{
		ft_putendl("yuvir is a bish <3");
		data.directory = opendir(tmp[i]);
		list = NULL;
		while ((data.file = readdir(data.directory)) != NULL)
		{
			if (data.file->d_name[0] == '.')
				continue;
			list = add_node(list, data.file->d_name);
		}
		ft_sort(list);
		ft_print_list(list);
		closedir(data.directory);
		i++;
	}
}