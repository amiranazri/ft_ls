#ifndef		FT_LS_H
# define	FT_LS_H
#include	"libft/libft.h"
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<uuid/uuid.h>
#include	<pwd.h>
#include	<grp.h>
#include	<errno.h>
#include	<time.h>
#include	<dirent.h>

typedef struct s_list
{
	DIR		*directory;
	struct	dirent *file;
	struct	s_list *next;
	struct	group *group_ptr;
	struct	passwd *password_ptr;
	struct	stat status;
	struct	passwd password;
	struct	group group;
	struct	tm time;
	char	flag;
	char	*buf;
	char	*tmp;
	char	**buffer;
	char	*item_name;
	char	*path;
}				t_list;

void	ft_ls(char *tmp);
void	arguments(char *tmp);
void	ft_ls_r(t_list *items);
void	ft_ls_R(const char *tmp);
void	ft_ls_a(char *tmp);
void	ft_ls_l(char *tmp);
// void 	sort(t_list **list, int(*cmp)(t_list *, t_list *));

#endif