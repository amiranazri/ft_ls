#include "ft_ls.h"

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

void  ft_check(char *tmp)
{
   struct stat status;

   if(stat(tmp, &status) == -1) 
      ft_putendl("ls: No such file or directory.");
   else if (S_ISDIR(status.st_mode))
      ft_ls(tmp);
   else
      ft_putendl(tmp);
}

int	main(int ac, char **av)
{
   char  *flag1;
   char  *flag2;

   flag1 = (av[1]);
   flag2 = (av[2]);
   if (ac == 1)
   {
      ft_ls(".");
      return (0);
   }
   if (av[1][0] != 45)
   {
      ft_check(av[1]);
      return (0);
   }
   // if (!(ft_strncmp(flag1, "-", 9)))
   // {
   //    ft_putendl("ls: No such file or directory.\n");
   //    return 0;
   // }
   if (ac >= 2 && has_flags(av[1]) == false)
      arguments(av[1]);
   else if (ac >= 2 && has_flags(av[1]) == true)
   {
      ac == 2 && is_recursive(av[1]) ? ft_ls_recursive(".") :
      ac == 3 && is_recursive(av[1]) ? ft_ls_recursive(av[2]) :
      ac == 2 && is_reversed(av[1]) ? ft_ls_r(".") :
      ac == 3 && is_reversed(av[1]) ? ft_ls_r(av[2]) :
      ac == 2 && has_a(av[1]) ? ft_ls_a(".") :
      ac == 3 && has_a(av[1]) ? ft_ls_a(av[2]) :
      ac == 2 && has_l(av[1]) ? ft_ls_l(".") :
      ac == 3 && has_l(av[1]) ? ft_ls_l(av[2]) :
      ac == 2 && has_t(av[1]) ? ft_ls_t(".") :
      ac == 3 && has_t(av[1]) ? ft_ls_t(av[2]) : ft_putstr("ls: No such file or directory.\n");
   }
   // sleep(30);
   return (0);
}