#include "ft_ls.h"

void	ft_ls_recursive(const char *tmp)
{
	t_list data;

	data.directory = opendir(tmp);
	tmp = ft_strdup(tmp);
	tmp = ft_strjoin(tmp, "/");
	if (!data.directory)
	{
		ft_putendl("ls: XX: No such file or directory");
		return ;
	}
	while ((data.file = readdir(data.directory)) != NULL)
	{
		if ((data.file->d_type) == DT_DIR)
		{
			data.buf = ft_strnew(1024);
			if ((ft_strcmp(data.file->d_name, ".")) == 0 || (ft_strcmp(data.file->d_name, "..")) == 0)
				continue;
			data.buf = ft_strjoin(tmp, data.file->d_name);
			ft_putendl(data.file->d_name);
			ft_ls_recursive(data.buf);
		}
		else
			ft_putendl(data.file->d_name);
	}
	free(data.buf);
	closedir(data.directory);
}