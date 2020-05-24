#include "libft/ft_putendl.c"
#include "libft/ft_putchar.c"
#include "libft/ft_putstr.c"
#include "libft/ft_strcmp.c"

typedef struct s_list
{
	// DIR		*directory;
	// struct	dirent *file;
	 struct	s_list *next;
	// // struct	group *group_ptr;
	// // struct	passwd *password_ptr;
	// struct	stat status;
	// // struct	passwd password;
	// // struct	group group;
	// struct	tm time;
	// char	flag;
	// char	*buf;
	// char	*tmp;
	 char	*data_name;
	// char	**buffer;
	// char	*path;
}				t_list;

void ft_sort(t_list *tmp)
{
    t_list  *start;
    char    *cont;

    start = tmp;
    while (tmp->next != NULL)
    {   
        if (tmp == NULL)
            tmp = tmp->next;
        if (ft_strcmp(tmp->data_name, tmp->next->data_name) > 0)
        {
            //swap values around
            cont = tmp->data_name;
            tmp->data_name = tmp->next->data_name;
            tmp->next->data_name = cont;
        }
        else 
            tmp = tmp->next; 
    }
}

int main()
{
    t_list *list;

    list = (t_list *)malloc(sizeof(t_list));
    list->data_name = "jelly";
    list->next = (t_list *)malloc(sizeof(t_list));
    list->next->data_name = "bananas";
    list->next->next = (t_list *)malloc(sizeof(t_list));
    list->next->next->data_name = "cofefe";
    list->next->next->next = (t_list *)malloc(sizeof(t_list));
    list->next->next->next = NULL;

    ft_sort(list);
    while (list != NULL)
    {
        ft_putendl(list->data_name);
        list = list->next;
    }
}