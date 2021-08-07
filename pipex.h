#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_struct
{
	int			files_fd[2];
	int			pipe_fd[2];
	int			*fd;
	char		*file1;
	char		**ft_cmds;
	char		***cmds;
	char		*file2;
}				t_struct;

void	ft_error(const char *str);
void	free_all(t_struct *global);
char	*ft_strjoin_new(char *s1, char *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_getpath(char *path, char **envp);
void	pipe_first_cmd(t_struct *global, char **envp);
void	pipe_second_cmd(t_struct *global, char **envp);

#endif