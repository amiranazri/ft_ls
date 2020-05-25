#include "ft_ls.h"

void ft_ls(char *tmp)
{
	t_list	data;
	t_list	list;
	t_list	*head;
	t_list	*store;

	head = NULL;
	data.buf = ft_strjoin(tmp, data.file->d_name);
	store = (t_list *)malloc(sizeof(data.buf));
	data.directory = opendir(".");
	while ((data.file = readdir(data.directory)) != NULL)
	{
	
		stat(data.buf, &data.status);  
		// add_node(head, data.buf);
		ft_sort(store);
		ft_putchar(32);
		// print_list(head);
		// ft_putendl(store);
		//free(data.buf);
	}
	closedir(data.directory);
}

