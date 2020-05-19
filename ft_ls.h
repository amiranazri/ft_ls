#include <dirent.h>

typedef struct s_list
{
	DIR *directory;
	struct s_list *data;
	struct s_list *next;
}		t_list;
