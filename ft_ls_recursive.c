#include "ft_ls.h"

void	ft_ls_recursive(const char *tmp)
{
	t_list	data;
	struct stat	status;

	data.directory = opendir(tmp);
	tmp = ft_strdup(tmp);
	tmp = ft_strjoin(tmp, "/");
	if (!data.directory)
	{
		ft_putendl("ls: No such file or directory. ");
		ft_putchar(10);
		return ;
	}
	while ((data.file = readdir(data.directory)) != NULL)
	{
		if ((data.file->d_type) == DT_DIR)
		{
			data.buf = ft_strnew(1024);
			if (data.file->d_name[0] == '.')
				continue;
			data.buf = ft_strjoin(tmp, data.file->d_name);
			ft_putchar(10);
			ft_putstr("./");
			ft_putendl(data.file->d_name);
			ft_ls_recursive(data.buf);
		}
		else
			ft_putendl(data.file->d_name);
	}
	free(data.buf);
	closedir(data.directory);
}