#include "ft_ls.h"

void ft_ls(char *tmp)
{
	t_list data;
	data.directory = opendir(".");
	tmp = ft_strdup(".");
	tmp = ft_strjoin(tmp, "/");
	while ((data.file = readdir(data.directory)) != NULL)
	{
		data.buf = ft_strjoin(tmp, data.file->d_name);
		stat(data.buf, &data.status);
		ft_putchar(32);
		ft_putendl(data.file->d_name);
		free(data.buf);
	}
	closedir(data.directory);
}