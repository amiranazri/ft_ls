#include "ft_ls.h"

// void ft_ls_l(char *tmp)
// {
// 	int	i;
// 	t_list data;

// 	if (!(data.directory = opendir(tmp)))
// 	return;
	
//     data.buffer = (char **)malloc(sizeof(data.directory) + 1);
	
//     i = 0;
// 	while(data.file == readdir(data.directory))
// 	{
// 		data.buffer[i] = ft_strdup((data.file)->d_name);
// 		i++;
// 	}
	
//     // ft_sort(&data, sizeof(data.directory));
// 	i = 0;
// 	while (data.buffer[i])
//     {
//         ft_putendl(data.buffer[i++]);
//         closedir(data.directory);
//     }
// }

void ft_ls_l(char *tmp)
{
	t_list	data;
	t_list	pos;
	t_list	*list;

	data.directory = opendir(".");
	list = NULL;
	while ((data.file = readdir(data.directory)) != NULL)
	{
		if (data.file->d_name[0] == '.')
			continue;
		list = add_node(list, data.file->d_name, 0);
	}
	ft_sort(list);
	print_list(list);
	closedir(data.directory);
}