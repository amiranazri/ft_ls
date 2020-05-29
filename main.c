#include "ft_ls.h"

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

t_bool	has_flags(char *flag)
{
   return (flag[0] == '-' ? true : false);
}

t_bool	is_recursive(char *flag)
{
   return (flag[1] == 'R' ? true : false);
}

t_bool	is_reversed(char *flag)
{
   return (flag[1] == 'r' ? true : false);
}

t_bool	has_a(char *flag)
{
   return (flag[1] == 'a' ? true : false);
}

t_bool   has_l(char *flag)
{
   return (flag[1] == 'l' ? true : false);
}

t_bool   has_t(char *flag)
{
   return (flag[1] == 't' ? true : false);
}

// void deleteAllNodes(t_list *start)
// {
//    t_list *tmp;
//     while (start != NULL)
//     { 
//         tmp = start; 
//         start = start -> next;
//         free(tmp);
//     }
// }

int	main(int ac, char **av)
{
   if (ac == 1)
      ft_ls(".");
   if (ac >= 2 && has_flags(av[1]) == false)
      arguments(av[1]);
   else if (ac >= 2 && has_flags(av[1]) == true)
   {
      if (ac == 2 && is_recursive(av[1]))
         ft_ls_recursive(".");
      else if (ac == 3 && is_recursive(av[1]))
         ft_ls_recursive(av[2]);
      else if (ac == 2 && is_reversed(av[1]))
         ft_ls_r(".");
      else if (ac == 3 && is_reversed(av[1]))
         ft_ls_r(av[2]);
      else if (ac == 2 && has_a(av[1]))
         ft_ls_a(".");
      else if (ac == 3 && has_a(av[1]))
         ft_ls_a(av[2]);
      else if (ac == 2 && has_l(av[1]))
         ft_ls_l(".");
      else if (ac == 3 && has_l(av[1]))
         ft_ls_l(av[2]);
         else if (ac == 2 && has_t(av[1]))
         ft_ls_t(".");
      else if (ac == 3 && has_t(av[1]))
         ft_ls_t(av[2]);
      else
         ft_putendl("error message ...");
   }
   // sleep(30);
   return (0);
}
