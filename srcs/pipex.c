#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	int fd[2];
	int pid1;
	int pid2;
	int  fdin;
	int  fdout;
	char  **cmd1;
	char  **cmd2;
//	char *cmd1[] = {"/bin/ls", "-a",NULL};
//	char *cmd2[] = {"/usr/bin/cat", "-e",NULL};
	(void)ac;
//	cmd1 = (char **)malloc(sizeof(char *));
//	cmd2 = (char **)malloc(sizeof(char *));
	cmd1 = ft_split(av[2], ' ');
	cmd2 = ft_split(av[3], ' ');
//	cmd1[0] = (char *)malloc(31);
//	cmd2[0] = (char *)malloc(31);
	cmd1[0] = check_commands(av[2], envp);
	printf("comando %s\nopcao %s\n", cmd1[0], cmd1[1]);
	cmd2[0] = check_commands(av[3], envp);
	if (pipe(fd) == -1)
		exit(0);
	pid1 = fork();
	if (pid1 == 0)
	{
		fdin = open("file1", O_RDWR);
		dup2(fdin, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execve(cmd1[0], cmd1, envp);
		close(fdin);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		fdout = open("file2", O_RDWR);
		dup2(fdout, 1);
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execve(cmd2[0], cmd2, envp);
		close(fdout);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
    return 0;
}
