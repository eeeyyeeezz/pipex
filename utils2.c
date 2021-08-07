#include "pipex.h"

void ft_error(const char *str)
{
	write(1, str, ft_strlen((char *)str));
	exit(0);
}

static	int	ft_ft_strncmp(char *str1, char *str2, int len)
{
	int		i;

	i = 0;
	while (str1[i] == str2[i] && str1 && str2 && len--)
		i++;
	if ((!str1 && !str2) || !len)
		return (1);
	else 
		return (0);
}

char		*ft_getpath(char *path, char **envp)
{
	int		j;
	int		i;
	char	*path_string;

	j = 0;
	i = 0;
	path_string = malloc(sizeof(char) * 10);
	if (!path_string)
		ft_error("Malloc Error!\n");
	while (envp[i])
	{
		if (ft_ft_strncmp(envp[i], path, 5))
		{
			while (envp[i][j] != '=')
				j++;
			path_string = (char *)&envp[i][j + 1];
			break ;
		}
		i++;
	}
	return (path_string);
}