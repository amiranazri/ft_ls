#include "ft_ls.h"

int ft_isdir(char *args)
{
   t_list   current;

   if ((current.directory = opendir(args)) != NULL)
   {
      while ((current.file = readdir(current.directory)))
      {
         if ((current.file)->d_type == DT_DIR)
            return (true);
      }
      closedir(current.directory);
   }
   return (0);
}

// t_bool ft_isreg(char **args)
// {
//    int         ret;
//    struct stat *status;

//    status = NULL;
//    ret = (S_ISREG(stat(*args, status)) ? true : false);
//    return (ret);
// }

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

t_list  *ft_store_files(int ac, char **av)
{
   int         i;
   t_list      *items;
   struct stat status;

   i = 1;
   items = NULL;
   while (ac > i)
   {
      if (av[i][0] != 45)
      {
         if (stat(av[i], &status))
            ft_putendl("No such file or directory.");
         else
            items = add_node(items, av[i]);
      }
      i++;
   }
   return (items);
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
   if (store[0] == '\0')
      return (NULL);
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
   t_list   *store;

   i = 1;
   j = 0;
   if (ac == 1)
      ft_ls(".");
   if (ac >= 2 && ac < 6)
   {
      //seperate non essentials and store flags.
      str = ft_parse_flags(ac, av);
      store = ft_store_files(ac, av);
      if(store != NULL && str == NULL)
      {
         while (store != NULL)
         {
            if (ft_isdir(store->data_name))
               ft_ls(store->data_name);
            else
               ft_putendl(store->data_name);
            store = store->next;
         }
      }
      else if (str != NULL && store == NULL)
      {
         if (ft_strchr(str, FLAGS[0]) != NULL)
            ft_ls_recursive(".");
         else if (ft_strchr(str, FLAGS[1]) != NULL)
            ft_ls_a(".");
         else if (ft_strchr(str, FLAGS[2]) != NULL)
            ft_ls_l(".");
         else if (ft_strchr(str, FLAGS[3]) != NULL)
            ft_ls_t(".");
         else if (ft_strchr(str, FLAGS[4]) != NULL)
            ft_ls_r(".");
      }
      else if (store != NULL && str != NULL)
      {
         while (store != NULL)
         {
            if (ft_isdir(store->data_name))
            {
               if (ft_strchr(str, FLAGS[0]) != NULL)
                  ft_ls_recursive(store->data_name);
               else if (ft_strchr(str, FLAGS[1]) != NULL)
                  ft_ls_a(store->data_name);
               else if (ft_strchr(str, FLAGS[2]) != NULL)
                  ft_ls_l(store->data_name);
               else if (ft_strchr(str, FLAGS[3]) != NULL)
                  ft_ls_t(store->data_name);
               else if (ft_strchr(str, FLAGS[4]) != NULL)
                  ft_ls_r(store->data_name);
            }
            else
               ft_putendl(store->data_name);
            store = store->next;
         }
      }
      i++;
      }
   return (0);
   }