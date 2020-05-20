#include "ft_ls.h"

void	arguments(char *tmp)
{
	t_list data;

	data.directory = opendir(tmp);
	tmp = ft_strdup(tmp);
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