#include "../pipex.h"

void	split_to_struct(t_struct *global, char **cmds)
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
}

void	pars_args_heredoc(t_struct *global, char **argv)
{
	char	**cmds;

	cmds = malloc(sizeof(char *) * 3);
	if (!cmds)
		ft_error("Malloc Error!\n");
	cmds[0] = argv[3];
	cmds[1] = argv[4];
	cmds[2] = NULL;
	split_to_struct(global, cmds);
	free(cmds);
	cmds = NULL;
}

void	pars_args(t_struct *global, int argc, char **argv, int flag)
{
	int		count;
	char	**cmds;
	int		i;

	i = 0;
	count = 2;
	cmds = malloc(sizeof(char *) * (argc - 2));
	if (!cmds)
		ft_error("Malloc Error!\n");
	while (count < argc - 1)
		cmds[i++] = argv[count++];
	cmds[i] = NULL;
	if (flag == 1)
	{
		split_to_struct(global, cmds);
		free(cmds);
		cmds = NULL;
	}
	else
		global->ft_cmds = cmds;
}

void	open_all_bonus(t_struct *global, int argc, char **argv, int flag)
{
	if (flag == 0)
		global->files_fd[1] = open(argv[argc - 1],
				O_APPEND | O_WRONLY | O_CREAT, 0666);
	else if (flag == 1)
	{
		global->files_fd[0] = open(argv[1], O_RDONLY);
		global->files_fd[1] = open(argv[argc - 1],
				O_TRUNC | O_WRONLY | O_CREAT, 0666);
	}
	if (global->files_fd[0] == -1 || global->files_fd[1] == -1)
		ft_error("Fd Error!\n");
}
