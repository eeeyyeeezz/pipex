#include "pipex.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
	// printf("\nAB [%s] [%s]\n", s1, s2);
	while (*s1++ == *s2++ && *s1 && *s2)
		;
	if (!*s1 && !*s2)
		return (0);
	else
		return (1);
}

char		*ft_strjoin_new(char *s1, char *s2)
{
	char	*ptr_free;

	ptr_free = s1;
	if (!(s1 = ft_strjoin(s1, s2)))
		return (NULL);
	free(ptr_free);
	return (s1);
}

void		pipe_first_cmd(t_struct *global, char **envp)
{
	int		i;
	char	*cmd_join;
	char	**args;
	char	**splitted;

	i = -1;
	dup2(global->pipe_fd[1], 1);
	close(global->pipe_fd[0]);
	close(global->pipe_fd[1]);
	args = ft_split(global->ft_cmds[0], ' ');
	splitted = ft_split(ft_getpath("PATH=", envp), ':');
	while (splitted[++i])
	{
		cmd_join = ft_strjoin_new(splitted[i], "/");
		cmd_join = ft_strjoin_new(cmd_join, args[0]);
		if (!access(cmd_join, 00))
		{ 
			execve(cmd_join, args, envp);
			free(args);
			exit(0);
		}
	}
}

void		pipe_second_cmd(t_struct *global, char **envp)
{
	int		i;
	char	**splitted;	
	char	*cmd_join;
	char	**args;

	i = -1;
	dup2(global->pipe_fd[0], 0);
	close(global->pipe_fd[0]);
	close(global->pipe_fd[1]);
	args = ft_split(global->ft_cmds[1], ' ');
	splitted = ft_split(ft_getpath("PATH=", envp), ':');
	while (splitted[++i])
	{
		cmd_join = ft_strjoin_new(splitted[i], "/");
		cmd_join = ft_strjoin_new(cmd_join, args[0]);
		if (!access(cmd_join, 00))
		{ 
			execve(cmd_join, args, envp);
			free(args);
			exit(0);
		}
	}
}