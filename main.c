#include "ft_ls.h"

// t_bool	has_flags(char *flag)
// {
//    return (flag[0] == '-' ? true : false);
// }

// t_bool	has_a(char *flag)
// {
//    return (flag[1] == 'a' ? true : false);
// }

// t_bool   has_l(char *flag)
// {
//    return (flag[1] == 'l' ? true : false);
// }

// t_bool	is_recursive(char *flag)
// {
//    return (flag[1] == 'R' ? true : false);
// }

// t_bool	is_reversed(char *flag)
// {
//    return (flag[1] == 'r' ? true : false);
// }

int	main(int ac, char **av)
{
   if (ac == 1)
      ft_ls(".");
   if (ac >= 2 && has_flags(av[1]) == false)
      args(av[1]);
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
      else
         ft_putendl("The specified flags do not exist.");
   }
   return (0);
}