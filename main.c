#include "ft_ls.h"

void  ft_error(char *av)
{

   ft_putstr("ls: illegal option -- ");
   ft_putchar(av[1]);
   ft_putchar(10);
   ft_putstr("usage: ls [-@Ralr\%] [file ...]");
}

// void  ft_data_type(char *tmp, char **av)
// {
//    int         i;
//    struct stat status;

//    i = 0;
//    if(stat(tmp, &status) == -1) 
//       ft_error(tmp);
//    else if (S_ISDIR(status.st_mode))
//       ft_ls(&tmp);
//    else if (S_ISREG(status.st_mode))
//    {
//       ft_ls(av[i]);
//       i++;
//    }
//    else
//       ft_putendl(tmp);
// }

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

t_bool ft_is_valid(char **args)
{
   int      i;
   int      j;
   int      ret;

   i = 1;
   j = 0;
   ret = 0;
   while (args[i])
   {
      if (args[i][j] == 45)
      {
         while (FLAGS[j])
         {
            args[i][1] == FLAGS[j] ? ret = 1 : j++;
            args[i][1] == FLAGS[j] ? ret = 1 : j++;
            args[i][1] == FLAGS[j] ? ret = 1 : j++;
            args[i][1] == FLAGS[j] ? ret = 1 : j++;
            args[i][1] == FLAGS[j] ? ret = 1 : j++;
         }
         if (FLAGS[j] == 0)
         {
            ft_error(*args);
            break ;
         }
         else
            i++;
      }
   }
   return (ret);
}

t_bool   file_l(char *name)
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
   ft_putendl("No such file or directory");
   return (false);
}

int   main(int ac, char **av)
{
   int      i;
   int      j;
   t_list   data;
   char     *store;

   i = 0;
   j = 0;
   if (ac == 1)
      ft_ls(".");
   if (ac >= 2 && ac < 6)
   {
      if (av[1][0] != 45)
      {
         if (ft_isdir(&av[1]) == true)
            data.directory = opendir(av[1]);
         else
         {
            file_l(av[1]);
            return (0);
         } 
      }
      if (ft_is_valid(av) == 1)
      {
         if (ft_strchr(av[1], FLAGS[j]) != NULL)
         {
            
         }
         
      }
   }
}