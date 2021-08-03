#include "pipex.h"

static int		memory_len(char const *s, char c)
{
	int j;
	int n;
	int i;

	j = 0;
	i = 0;
	n = 0;
	while (s[i])
	{
		if (j == 1 && s[i] == c)
			j = 0;
		if (j == 0 && s[i] != c)
		{
			j = 1;
			n++;
		}
		i++;
	}
	return (n);
}

static	char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		s_start;
	char		*sub;

	i = 0;
	s_start = start;
	sub = malloc(len + 1);
	if (sub == NULL || s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub[i] = '\0';
		return (sub);
	}
	while (len-- && s[start])
		sub[i++] = s[s_start++];
	sub[i] = '\0';
	return (sub);
}

char			**ft_split(char const *s, char c)
{
	int		arr[3];
	char	**temp;

	arr[0] = 0;
	arr[2] = -1;
	if (!s)
		return (NULL);
	if (!(temp = malloc(sizeof(char *) * (memory_len(s, c) + 1))))
		return (NULL);
	while (++arr[2] < memory_len(s, c))
	{
		while (s[arr[0]] == c && s[arr[0]])
			arr[0]++;
		arr[1] = arr[0];
		while (s[arr[0]] != c && s[arr[0]])
			arr[0]++;
		temp[arr[2]] = ft_substr(s, arr[1], arr[0] - arr[1]);
		arr[0]++;
	}
	temp[arr[2]] = NULL;
	return (temp);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*new_string;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_string == NULL)
		return (NULL);
	while (*s1)
		new_string[i++] = *s1++;
	while (*s2)
		new_string[i++] = *s2++;
	new_string[i] = '\0';
	return (new_string);
}

char		*ft_strjoin_new(char *s1, char *s2)
{
	char	*ptr_free;

	ptr_free = s1;
	if (!(s1 = ft_strjoin(s1, s2)))
		return (NULL);
	free(ptr_free);
	return (s1);
}
