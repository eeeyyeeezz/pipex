#include "pipex.h"

static void	ft_execve(char **args, char **envp)
{
	int		i;
	char	*cmd_join;
	char	**splitted;

	i = -1;
	splitted = ft_split(ft_getpath("PATH=", envp), ':');
	while (splitted[++i])
	{
		cmd_join = ft_strjoin_new(splitted[i], "/");
		cmd_join = ft_strjoin_new(cmd_join, args[0]);
		if (!access(cmd_join, 00))
		{
			execve(cmd_join, args, envp);
			exit(0);
		}
	}
}

static void	ft_pipe(t_struct *global, char **envp, int pipe_fd[2], int fdd)
{
	dup2(fdd, 0);
	if (*(global->cmds + 1) != NULL)
		dup2(pipe_fd[1], 1);
	else
		dup2(global->files_fd[1], 1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	ft_execve(*global->cmds, envp);
}

static void	ft_pipex_bonus(t_struct *global, int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		fdd;
	pid_t	pid;

	fdd = 0;
	dup2(global->files_fd[0], 0);
	dup2(global->files_fd[1], 1);
	while (*global->cmds != NULL)
	{
		if (pipe(pipe_fd) == -1)
			ft_error("Pipe Error!\n");
		pid = fork();
		if (pid == -1)
			ft_error("Fork Error mda!\n");
		else if (pid == 0)
			ft_pipe(global, envp, pipe_fd, fdd);
		else
		{
			wait(NULL);
			close(pipe_fd[1]);
			fdd = pipe_fd[0];
			global->cmds++;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_struct	global;

	if (argc < 5)
		ft_error("Args Error!\n");
	if (!ft_strcmp(argv[1], "here_doc") && argc == 6)
	{
		pars_args_heredoc(&global, argc, argv);
		open_all_bonus(&global, argc, argv, 0);
		do_heredoc(&global, argc, argv);
		ft_pipex_bonus(&global, argc, argv, envp);
	}
	else
	{
		pars_args(&global, argc, argv, 1);
		open_all_bonus(&global, argc, argv, 1);
		ft_pipex_bonus(&global, argc, argv, envp);
	}
}
