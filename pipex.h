#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_struct
{
	int			files_fd[2];
	int			fd[2];
	char		*file1;
	char		**cmds;
	char		*file2;
}				t_struct;

int		ft_strlen(char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	free_all(t_struct *global);
void	ft_error(const char *str);


#endif