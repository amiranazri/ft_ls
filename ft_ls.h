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
	// struct	group group;
	// struct	group *group_ptr;
	// struct	passwd *password_ptr;
	// struct	stat status;
	// struct	passwd *password;
	struct	node *node;
	struct	tm time;
	char	flag;
	char	*buf;
	char	*tmp;
	char	*data_name;
	char	**buffer;
	char	*path;
	long	date;
}				t_list;

int		ft_blocks(t_list *tmp);
void 	ft_check(char *tmp);
void	ft_ls(char *tmp);
void	arguments(char *tmp);
void    ft_print_list(t_list *head);
void    insert_node(char *file_name, t_list *node);
void	ft_ls_recursive(const char *tmp);
void	ft_ls_r(char *tmp);
void	ft_ls_a(char *tmp);
void	ft_ls_t(char *tmp);
void	ft_ls_l(char *tmp);
void	ft_ls_long(char *tmp);
void	ft_loop_list(t_list *tmp);
void	ft_sort(t_list *tmp);
void	ft_reverse_sort(t_list *tmp);
void	ft_time_sort(t_list *tmp);
// void	deleteAllNodes(t_list *start);
int		ft_blocks(t_list *tmp);
t_list	*add_node(t_list *head, char *file_name); 

#endif