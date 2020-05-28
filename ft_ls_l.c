#include "ft_ls.h"

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

	i = 0;
	if(stat(tmp, &status) < 0)
		return ;
	ft_permissions(status);
	ft_putchar(32);
	ft_putnbr(status.st_nlink);
	ft_putchar(9);
	if((password = getpwuid(status.st_uid) != 0))
	{
		ft_putstr(password->pw_name);
		ft_putchar(32);
	}
	if ((password = getgrid(status.st_gid) != 0))
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