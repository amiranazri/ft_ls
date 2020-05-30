#include "ft_ls.h"

static t_bool	has_flags(char *flag)
{
   return (flag[0] == '-' ? true : false);
}

void  ft_data_type(char *tmp)
{
   struct stat status;

   if(stat(tmp, &status) == -1) 
      ft_putendl("ls: No such file or directory.");
   else if (S_ISDIR(status.st_mode))
      ft_ls(tmp);
   else
      ft_putendl(tmp);
}

void  ft_error(char **av)
{
   ft_putstr("ls: illegal option -- ");
   ft_putstr(av[1]);
   ft_putchar(10);
   ft_putstr("usage: ls [-@Ralr\%] [file ...]");
}

int main (int ac, char **av)
{
   int   i;
   char  *flag;

   i = 0;
   flag = NULL;
   if (av[1][0] != 45)
   {
      ft_error(&av[1]);
      return (0);
   }
   if (ac == 1)
   {
      ft_ls(".");
      return (0);
   }
   if (ac >= 2 && has_flags(av[1]) == false)
      arguments(av[1]);
   else if (ac >= 2 && has_flags(av[1]) == true)
   {
      while (i > 0 && i < 6)
      {
         if (ac == 2 && flag[i] == 'a')
            ft_ls_a(".");
         else if (ac == 3 && flag[i] == 'a')
            ft_ls_a(av[2]);
         if (ac == 2 && flag[i] == 'r')
            ft_ls_r(".");
         else if (ac == 3 && flag[i] == 'r')
            ft_ls_r(av[2]);
         if (ac == 2 && flag[i] == 't')
            ft_ls_t(".");
         else if (ac == 3 && flag[i] == 't')
            ft_ls_t(av[2]);
         if (ac == 2 && flag[i] == 'l')
            ft_ls_l(".");
         else if (ac == 3 && flag[i] == 'l')
            ft_ls_l(av[2]);
         if (ac == 2 && flag[i] == 'R')
            ft_ls_recursive(".");
         else if (ac == 3 && flag[i] == 'R')
            ft_ls_recursive(av[2]);   
         else
         {
            ft_putstr("ls: illegal option -- ");
            ft_putstr(av[1]);
            ft_putchar(10);
            ft_putstr("usage: ls [-@Ralr\%] [file ...]");
         }
      }
   }
   // sleep(30);
   return (0);
}