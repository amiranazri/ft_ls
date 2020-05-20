#include "ft_ls.h"

void	ft_ls_recursive(const char *tmp)
{
	t_list data;

	data.directory = opendir(tmp);
	tmp = ft_strdup(tmp);
	tmp = ft_strjoin(tmp, "/");
	if (!data.directory)
	{
		ft_putendl("Directory cannot be opened.");
		return ;
	}
	while ((data.file = readdir(data.directory)) != NULL)
	{
		//dt_dir = a directory
		if ((data.file->d_type) == DT_DIR)
		{
			//dynamically allocates 1024 bytes in buf
			data.buf = ft_strnew(1024);
			if ((ft_strcmp(data.file->d_name, ".")) == 0 || (ft_strcmp(data.file->d_name, "..")) == 0)
				continue;
			data.buf = ft_strjoin(tmp, data.file->d_name);
			//dname = name of directory or file currently listed
			ft_putendl(data.file->d_name);
			ft_ls_recursive(data.buf);
		}
		else
			ft_putendl(data.file->d_name);
	}
	free(data.buf);
	closedir(data.directory);
}