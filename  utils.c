#include "pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void ft_error(const char *str)
{
	write(1, str, ft_strlen((char *)str));
	exit(0);
}

void	free_all(t_struct *global)
{
	int	i;

	i = -1;
	// while (global->cmds[++i])
	// 	free(global->cmds[i]);
	free(global->cmds);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1++ == *s2++ && *s1 && *s2)
		;
	if (!*s1 && !*s2)
		return (0);
	else
		return (1);
}