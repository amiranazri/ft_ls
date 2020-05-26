#include "ft_ls.h"

void ft_ls(char *tmp)
{
	// int		i;
	t_list	data;
	t_list	*list;
	t_list	*head;

	// i = 0;
	// head = NULL;
	data.directory = opendir(".");
	head = (t_list *)malloc(sizeof(t_list));
	// if
	while ((data.file = readdir(data.directory)) != NULL)
	{
		head->buf = data.file->d_name;
		add_node(head, data.buf);
		// ft_putendl(head->buf);
		// head = head->next;
		// ft_putendl(data.buf);
		// stat(data.buf, &data.status);  
		// ft_putchar(32);
		// print_list(head);
		// ft_putendl(store);
		//free(data.buf);
	}
	ft_sort(head);
	print_list(head);
	closedir(data.directory);
}