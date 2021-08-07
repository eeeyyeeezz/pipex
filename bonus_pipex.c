#include "pipex.h"

static	void	do_heredoc()
{
	printf("here_doc kek\n");
}

static	void	split_to_struct(t_struct *global, char **cmds)
{
	int	i;

	i = 0;
	global->cmds = malloc(sizeof(char ***) * 20);
	while (cmds[i])
	{
		global->cmds[i] = ft_split(cmds[i], ' ');
		i++;
	}
	global->cmds[i] = NULL;
	// for (int i = 0; global->cmds[i]; i++)
	// {
	// 	for (int j = 0; global->cmds[i][j]; j++)
	// 		printf("MEEh123 [%s]\n", global->cmds[i][j]);
	// }
}

static	void	pars_args(t_struct *global, int argc, char **argv)
{
	int	count;
	char	**cmds;
	int	i;
 
	i = 0;
	count = 2;
	cmds = malloc(sizeof(char *) * (argc - 2));
	global->fd = malloc(sizeof(int) * (argc - 2));
	if (!cmds || !global->fd)
		ft_error("Malloc Error!\n");
	global->file1 = argv[1];
	global->file2 = argv[argc - 1];
	while (count < argc - 1)
		cmds[i++] = argv[count++];
	cmds[i] = NULL;
	split_to_struct(global, cmds);
	free(cmds);
	cmds = NULL;
}

static	void	open_all(t_struct *global, int argc, char **argv)
{
	global->files_fd[0] = open(argv[1], O_RDONLY);
	global->files_fd[1] = open(argv[argc - 1], O_TRUNC | O_WRONLY | O_CREAT, 0666);
	if (global->files_fd[0] == -1 || global->files_fd[1] == -1)
		ft_error("Fd Error!\n");
}

static void	ft_pipex(t_struct *global, int argc, char **argv, char **envp)
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
			ft_error("Fork Error!\n");
		else if (pid == 0)
		{
			dup2(fdd, 0);
			if (*(global->cmds + 1) != NULL) 
				dup2(pipe_fd[1], 1);
			else
				dup2(global->files_fd[1], 1);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			execvp((*global->cmds)[0], *global->cmds);
			exit(0);
		}
		else 
		{
			wait(NULL);
			close(pipe_fd[1]);
			fdd = pipe_fd[0];
			global->cmds++;
		}
	}
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
	// free_all(&global);
	// execve("/bin/ls", argv, envp);
}