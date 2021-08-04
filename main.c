#include "pipex.h"

static	void	do_heredoc()
{
	printf("here_doc kek\n");
}

static	void	pars_args(t_struct *global, int argc, char **argv)
{
	int	count;
	int	i;

	i = 0;
	count = 2;
	global->cmds = malloc(sizeof(char *) * (argc - 2));
	global->fd = malloc(sizeof(int) * (argc - 2));
	if (!global->cmds || !global->fd)
		ft_error("Malloc Error!\n");
	global->file1 = argv[1];
	global->file2 = argv[argc - 1];
	while (count < argc - 1)
		global->cmds[i++] = argv[count++];
	global->cmds[i] = NULL;
	// for (int i = 0; global->cmds[i]; i++)
	// 	printf("CMDS [%s]\n", global->cmds[i]);
}

static	void	open_all(t_struct *global, int argc, char **argv)
{
	global->files_fd[0] = open(argv[1], O_RDONLY);
	global->files_fd[1] = open(argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0666);			 // bonus
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
	if (pid1 == 0)
	{
		dup2(global->pipe_fd[1], 1);
		close(global->pipe_fd[0]);
		close(global->pipe_fd[1]);
		args = ft_split(global->cmds[0], ' ');
		splitted = ft_split(getenv("PATH"), ':');
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
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(global->pipe_fd[0], 0);
		close(global->pipe_fd[0]);
		close(global->pipe_fd[1]);
		args = ft_split(global->cmds[1], ' ');
		splitted = ft_split(getenv("PATH"), ':');
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
	close(global->pipe_fd[0]);
	close(global->pipe_fd[1]);
	waitpid(pid1, NULL, 0); 
	waitpid(pid2, NULL, 0); 
}

int			main(int argc, char **argv, char **envp)
{
	t_struct	global;

	if (!ft_strcmp(argv[1], "here_doc"))
		do_heredoc();
	if (argc < 5)
		ft_error("Args Error!\n");
	pars_args(&global, argc, argv);
	open_all(&global, argc, argv);
	ft_pipex(&global, argc, argv, envp);
	free_all(&global);
	// execve("/bin/ls", argv, envp);
}