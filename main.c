#include "pipex.h"

static	void	open_all(t_struct *global, int argc, char **argv)
{
	global->files_fd[0] = open(argv[1], O_RDONLY);
	global->files_fd[1] = open(argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0666);
	if (global->files_fd[0] == -1 || global->files_fd[1] == -1)
		ft_error("Fd Error!\n");
	if (pipe(global->pipe_fd) == -1)
		ft_error("Pipe Error!\n");
}

static void	ft_pipex(t_struct *global, int argc, char **argv, char **envp)
{
	char	**splitted;
	char	*cmd_join;
	char	**args;
	int	i;
	int	pid1;
	int	pid2;

	i = -1;
	dup2(global->files_fd[0], 0);
	dup2(global->files_fd[1], 1);
	pid1 = fork();
	if (pid1 == -1)
		ft_error("Fork Error!\n");
	else if (pid1 == 0)
		pipe_first_cmd(global, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("Fork Error!\n");
	else if (pid2 == 0)
		pipe_second_cmd(global, envp);
	close(global->pipe_fd[0]);
	close(global->pipe_fd[1]);
	waitpid(pid1, NULL, 0); 
	waitpid(pid2, NULL, 0); 
}

int			main(int argc, char **argv, char **envp)
{
	t_struct	global;

	if (argc < 5)
		ft_error("Args Error!\n");
	pars_args(&global, argc, argv, 0);
	open_all(&global, argc, argv);
	ft_pipex(&global, argc, argv, envp);
	free(global.ft_cmds);
	while (1)
	{
		;
	}
}