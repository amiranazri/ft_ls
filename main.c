#include "ft_ls.h"

t_bool ft_isdir(char **args)
{
   int         ret;
   struct stat *status;

   status = NULL;
   ret = (S_ISDIR(stat(*args, status)) ? true : false);
   return (ret);
}

t_bool ft_isreg(char **args)
{
   int         ret;
   struct stat *status;

   status = NULL;
   ret = (S_ISREG(stat(*args, status)) ? true : false);
   return (ret);
}

t_bool   ft_is_valid(char option)
{
   if (ft_strchr(FLAGS, option) == NULL)
   {
      ft_error(option);
      return (false);
   }
   return (true);
}

void  ft_error(char option)
{
   ft_putstr("ls: illegal option -- ");
   ft_putchar(option);
   ft_putchar(10);
   ft_putstr("usage: ls [-@Ralr\%] [file ...]");
}

char  *ft_parse_flags(int ac, char **av)
{
   int   i;
   int   j;
   int   k;
   char  *store;

   i = 1;
   j = 0;
   k = 0;
   store = ft_strnew(1);
   while (ac > i)
   {
      if (av[i][j] == 45)
      {
         while (av[i][j])
         {
            j++;
            if (ft_is_valid(av[i][j]) == 1)
            {
               store[k] = av[i][j];
               k++;
               // j++;
            }
            else
               return (0);
         }  
      }
      i++;
   }
   store[k] = '\0';
   return (store);
}

t_bool   ft_check(char *name)
{
   t_list data;

   data.directory = opendir(".");
   while ((data.file = readdir(data.directory)) != NULL)
   {
      if(strcmp(data.file->d_name, name) == 0)
      {
         ft_putendl(data.file->d_name);
         return (true);
      }
      continue ;
   }
   ft_putendl("No such file or directory.");
   return (false);
}

int   main(int ac, char **av)
{
   int      i;
   int      j;
   char     *str;
   t_list   data;

   i = 1;
   j = 0;
   if (ac == 1)
      ft_ls(".");
   if (ac >= 2 && ac < 6)
   {
      //seperate non essentials and store flags.
      str = ft_parse_flags(ac, av);
      while (av[i])
      {
         if (av[i][0] != 45)
         {
            if (ft_isdir(&av[i]) == true)
               data.directory = opendir(av[i]);
            else
               ft_putendl(av[i]);
         }
         if (str != NULL)
         {
            if (ft_strchr(str, FLAGS[0]) != NULL)
               ft_ls_recursive(".");
            else if (ft_strchr(av[i], FLAGS[1]) != NULL)
               ft_ls_a(".");
            else if (ft_strchr(av[i], FLAGS[2]) != NULL)
               ft_ls_l(".");
            else if (ft_strchr(av[i], FLAGS[3]) != NULL)
               ft_ls_t(".");
            else if (ft_strchr(av[i], FLAGS[4]) != NULL)
               ft_ls_r(".");
         }
         i++;
      }
   }
}