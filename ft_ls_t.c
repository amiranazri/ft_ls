#include "ft_ls.h"

void ft_ls_t(char *tmp)
{
	t_list	data;
	t_list	*list;
	struct stat status;

	data.directory = opendir(".");
	list = NULL;
	while ((data.file = readdir(data.directory)) != NULL)
	{
		stat(data.file->d_name, &status);
		if (data.file->d_name[0] == '.')
			continue;
		list = add_node(list, data.file->d_name, ctime(&status.st_mtime));
	}
	ft_time_sort(list);
	print_list(list);
	closedir(data.directory);
}