#include "ft_ls.h"

void  ft_data_type(char *tmp)
{
   struct stat status;

   if(stat(tmp, &status) == -1) 
      ft_putendl("ls: No such file or directory.");
   else if (S_ISDIR(status.st_mode))
      ft_ls(&tmp);
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

int   main(int ac, char **av)
{
   int      i;
   char     flag;
   // struct   stat status;
   char     **flags;
   char     **directories;
 
   i = 1;
   directories = NULL;
   flags = NULL;
   if (ac == 1)
   {
      // stat(av[1], &status);
      // if (S_ISDIR(status.st_mode))
      // {
      //    ft_ls(av[1]);
      //    return (0);
      // }
      directories[0] = ".";
      ft_ls(directories);
      return (0);
   }
   // if (ac >= 2 && has_flags(av[1]) == false)
   //    arguments(av[1]);
   if (ac > 1)
   {
      while (i > 0 && i < ac)
      {
         if (av[i][0] == '-')
         {
            flag = av[i][1];
            if (flag == 'a')
               flags[i - 1] = av[i];
            else if (flag == 'a')
               flags[i - 1] = av[i];
            else if (flag == 'r')
               flags[i - 1] = av[i];
            else if (flag == 'r')
               flags[i - 1] = av[i];
            else if (flag == 't')
               flags[i - 1] = av[i];
            else if (flag == 't')
               flags[i - 1] = av[i];
            else if (flag == 'l')
               flags[i - 1] = av[i];
            else if (flag == 'l')
               flags[i - 1] = av[i];
            else if (flag == 'R')
               flags[i - 1] = av[i];
            else if (flag == 'R')
               flags[i - 1] = av[i];   
            else
            {
               ft_putstr("ls: illegal option -- ");
               ft_putchar(av[1][1]);
               ft_putchar(10);
               ft_putstr("usage: ls [-@Ralr\%] [file ...]");
            }
         }
         else
         {
            ft_putendl("here");
            //place directories into **directories
            directories[i - 1] = av[i];
         }
         i++;
      }   
   }
   ft_ls(directories);
   // sleep(30);
   return (0);
}