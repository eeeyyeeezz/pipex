#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_struct
{
	char		*file1;
	char		**cmds;
	char		*file2;
}				t_struct;



int	ft_strcmp(const char *s1, const char *s2);

#endif