#include "libft/ft_putendl.c"
#include "libft/ft_putchar.c"
#include "libft/ft_putstr.c"
#include "libft/ft_strcmp.c"

// typedef struct s_list
// {
// 	// DIR		*directory;
// 	// struct	dirent *file;
// 	 struct	s_list *next;
// 	// // struct	group *group_ptr;
// 	// // struct	passwd *password_ptr;
// 	// struct	stat status;
// 	// // struct	passwd password;
// 	// // struct	group group;
// 	// struct	tm time;
// 	// char	flag;
// 	// char	*buf;
// 	// char	*tmp;
// 	 char	*data_name;
// 	// char	**buffer;
// 	// char	*path;
// }				t_list;

// void ft_sort(t_list *tmp)
// {
//     t_list  *start;
//     char    *cont;

//     start = tmp;
//     while (tmp->next != NULL)
//     {   
//         if (tmp == NULL)
//             tmp = tmp->next;
//         if (ft_strcmp(tmp->data_name, tmp->next->data_name) > 0)
//         {
//             //swap values around
//             cont = tmp->data_name;
//             tmp->data_name = tmp->next->data_name;
//             tmp->next->data_name = cont;
//         }
//         else 
//             tmp = tmp->next; 
//     }
// }

// int main()
// {
//     t_list *list;

//     list = (t_list *)malloc(sizeof(t_list));
//     list->data_name = "jelly";
//     list->next = (t_list *)malloc(sizeof(t_list));
//     list->next->data_name = "bananas";
//     list->next->next = (t_list *)malloc(sizeof(t_list));
//     list->next->next->data_name = "cofefe";
//     list->next->next->next = (t_list *)malloc(sizeof(t_list));
//     list->next->next->next = NULL;

//     ft_sort(list);
//     while (list != NULL)
//     {
//         ft_putendl(list->data_name);
//         list = list->next;
//     }
// }

int ft_compare(const void *address1, const void *address2) 
{ 
    // Get the values at given addresses 
    int x = *(const int *)address1; 
    int y = *(const int *)address2; 

    // both odd, put the greater of two first. 
    if ((x&1) && (y&1)) 
        return (y-x); 
  
    // both even, put the smaller of two first 
    if ( !(x&1) && !(y&1) ) 
        return (x-y); 
  
    // l is even, put r first 
    if (!(x&1)) 
        return 1; 
  
    // l is odd, put l first 
    return -1; 
}

int main() 
{ 
    int arr[] = {1, 6, 5, 2, 3, 9, 4, 7, 8}; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
    qsort((void*)arr, size, sizeof(arr[0]), ft_compare); 
  
    printf("Output array is\n");
    printf("%i%d", &arr, &size);
  
    return 0; 
} 