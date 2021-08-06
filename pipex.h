#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_struct
{
	int			files_fd[2];
	int			pipe_fd[2];
	int			*fd;
	char		*file1;
	char		***cmds;
	char		*file2;
}				t_struct;

int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_new(char *s1, char *s2);
int		ft_strcmp(const char *s1, const char *s2);
void	free_all(t_struct *global);
void	ft_error(const char *str);


#endif