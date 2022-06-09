#include "pipex.h"

char	*ft_str_cmdpath(const char *s1)
{
	char	*str;
	size_t	i;
	size_t	a;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 2));
	if (!str)
		return (NULL);
	str[0] = '/';
	i = 1;
	a = -1;
	while (s1[++a] && s1[a] != ' ')
		str[i++] = s1[a];
	str[i] = 0;
	return (str);
}

char	*check_commands(char *raw_cmd, char **envp)
{
	short int	i;
	char		**paths;
	char		*path;
	char		*cmd;
	char		*tmp;
	i = -1;
	while(ft_memcmp(envp[++i], "PATH=", 5))
		;
//	printf("%d\n", i);
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	paths = ft_split(path, ':');
	cmd = ft_str_cmdpath(raw_cmd);
	printf("%s\n", cmd);
	int	a = -1;
	while (paths[++a])
	{
		tmp = ft_strjoin(paths[a], cmd);
		printf("%s\n", tmp);
		if (access(tmp, X_OK) == 0)
		{
				printf("Encontrou esta merda\n");
				return(tmp);
		}
	}
	printf("One of your commands is fucked\n");
	exit(0);
}
