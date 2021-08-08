#include "../pipex.h"

static	int get_next_line(char **line)
 {
	char buff;
	int i;
	int rb;
	 
	i = 0;
	*line = malloc(10000);
	while ((rb = read(0, &buff, 1)) > 0 && buff != '\n' && buff != '\0')
	{
		(*line)[i] = buff;
		i++;
	}
	(*line)[i] = '\0';
	if (rb > 0)
	 	return (1);
	else
		return (rb);
 }

void	do_heredoc(t_struct *global, int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*file;

	file = ".heredoc";
	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	if (fd < 0)
		ft_error("File error");
	write(1, "aboba> ", 7);
	while (get_next_line(&line) > 0 && ft_strcmp(line, argv[2]))
	{
		write(1, "aboba> ", 7);
		if (!ft_strncmp(line, argv[2], ft_strlen(argv[2]) + 1))
			break;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = NULL;
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("File error");
	// unlink(file);
	global->files_fd[0] = fd;
}