#include "ft_ls.h"

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
}

void ft_ls_l(char *tmp)
{
	int		i;
	char	**array;
	struct node		*node;
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
	
	password = getpwuid(status.st_uid);
	group = getgrgid(status.st_gid);
	if(password != NULL)
	{
		ft_putstr(password->pw_name);
		ft_putchar(32);
	}
	if ((group != NULL))
	{
		ft_putstr(group->gr_name);
		ft_putchar(9);
	}
	ft_putnbr(status.st_size);
	ft_putchar(9);
	array = (char **)malloc(sizeof(char *) + 20);
	array = ft_strsplit(ctime(&status.st_mtime), 32);
	ft_putstr(array[1]);
	ft_putchar(32);
	ft_putstr(array[2]);
	ft_putchar(32);
	while (i < 5)
	{
		ft_putstr(&array[3][i++]);
		ft_putchar(32);
		ft_putstr(tmp);
		ft_putchar(32);
		ft_putchar(10);
	}
	free(array);
}