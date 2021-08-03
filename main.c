#include "pipex.h"

static	void	do_heredoc()
{
	printf("here_doc kek\n");
}

int			main(int argc, char **argv, char **envp)
{
	if (!ft_strcmp(argv[1], "here_doc"))
		do_heredoc();
	// execve("/bin/ls", argv, envp);
}