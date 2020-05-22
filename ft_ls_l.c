#include "ft_ls.h"

void ft_ls_l(char *tmp)
{
	int	i;
	t_list data;

	if (!(data.directory = opendir(tmp)))
	return;
	
    data.buffer = (char **)malloc(sizeof(data.directory) + 1);
	
    i = 0;
	while(data.file == readdir(data.directory))
	{
		data.buffer[i] = ft_strdup((data.file)->d_name);
		i++;
	}
	
    // ft_sort(&data, sizeof(data.directory));
	i = 0;
	while (data.buffer[i])
    {
        ft_putendl(data.buffer[i++]);
        closedir(data.directory);
    }
}