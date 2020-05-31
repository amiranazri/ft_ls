#include "ft_ls.h"

void ft_loop_list(t_list *tmp)
{
	t_list	*list;

	list = tmp;
	while (list->next != NULL)
	{
		ft_ls_long(list->data_name);
		list = list->next;
	}
}

int	ft_blocks(t_list *tmp)
{
	int i;
	struct stat status;
	t_list	*cont;

	i = 0;
	cont = tmp;
	while(cont->next != NULL)
	{
		if(stat(cont->data_name,&status) < 0)
			return (0);
		i += status.st_blocks;
		cont = cont->next;
	}
	return (i);
}

void ft_permissions(struct stat status)
{
	(S_ISDIR(status.st_mode)) ? ft_putchar('d') : ft_putchar('-');
	(status.st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(status.st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	(status.st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(status.st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	(status.st_mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	(status.st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(status.st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	(status.st_mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
	(status.st_mode & S_ISVTX) ? ft_putchar('@') : ft_putchar('-');
}

void ft_ls_l(char *path)
{
	int		total_blocks;
	t_list	*list;
	t_list	data;

	data.directory = opendir(path);
	list = NULL;
	while ((data.file = readdir(data.directory)) != NULL)
	{
		if (data.file->d_name[0] == '.')
			continue;
		list = add_node(list, data.file->d_name);
	}
	 if (list != NULL)
        {
			ft_sort(list);
			total_blocks = ft_blocks(list);
			ft_putstr("total ");
			ft_putnbr(total_blocks);
			ft_putchar(10);
			ft_loop_list(list);
		}
	closedir(data.directory);
}

void ft_ls_long(char *tmp)
{
	int				i;
	char			*array1;
	char			*array2;
	struct group	*group;
	struct passwd	*password;
	struct stat		status;

	if(stat(tmp, &status) < 0)
		return ;
	i = 0;
	ft_permissions(status);
	ft_putchar(32);
	ft_putnbr(status.st_nlink);
	ft_putchar(9);

	if((password = getpwuid(status.st_uid)) != NULL)
	{
		ft_putstr(password->pw_name);
		ft_putchar(32);
	}
	if ((group = getgrgid(status.st_gid)) != NULL)
	{
		ft_putstr(group->gr_name);
		ft_putchar(9);
	}
	ft_putnbr(status.st_size);
	ft_putchar(9);
	array1 = ctime(&(status.st_mtime)) + 4;
	array2 = ft_strsub(array1, 0, 12);
	ft_putstr(array2);
	ft_putchar(32);
	ft_putstr(tmp);
	ft_putchar(32);
	ft_putchar(10);
	free(array2);
}