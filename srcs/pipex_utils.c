#include "pipex.h"

char	*ft_str_dup(const char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != ' ')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	check_commands(int ac, char **av, char **envp)
{
	short int	i;

	i = -1;
	(void)ac;
	(void)av;
	while(ft_memcmp(envp[++i], "PATH=", 5))
		;
	printf("%d\n", i);
}
