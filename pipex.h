#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_struct
{
	int			files_fd[2];
	int			pipe_fd[2];
	int			*fd;
	char		**ft_cmds;
	char		***cmds;
}				t_struct;

void	ft_error(const char *str);
char	*ft_strjoin_new(char *s1, char *s2);
char	*ft_getpath(char *path, char **envp);
int		ft_strcmp(const char *s1, const char *s2);
void	pipe_first_cmd(t_struct *global, char **envp);
void	split_to_struct(t_struct *global, char **cmds);
void	pipe_second_cmd(t_struct *global, char **envp);
void	do_heredoc(t_struct *global, char **argv);
void	pars_args_heredoc(t_struct *global, char **argv);
void	pars_args(t_struct *global, int argc, char **argv, int flag);
void	open_all_bonus(t_struct *global, int argc, char **argv, int flag);

#endif