/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:08:13 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/06/21 15:57:48 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_cmds	*cmds_initializer(t_cmds *cmds, char **av, char **envp, int i)
{
	cmds->cmd1 = ft_split(av[i - 1], ' ');
	cmds->cmd2 = ft_split(av[i], ' ');
	free(cmds->cmd1[0]);
	free(cmds->cmd2[0]);
	cmds->cmd1[0] = check_commands(av[i - 1], envp);
	arranjar_cmd(cmds->cmd1);
	cmds->cmd2[0] = check_commands(av[i], envp);
	arranjar_cmd(cmds->cmd2);
//	printf("cmd1: %s\ncmd2: %s\n", cmds->cmd1[0], cmds->cmd2[0]);
	return (cmds);
}

void	free_cmds(t_cmds *cmds)
{
	int	i;

	i = -1;
	while (cmds->cmd1[++i])
		free(cmds->cmd1[i]);
	i = 0;
	free(cmds->cmd1);
	while (cmds->cmd2[i])
		free(cmds->cmd2[i++]);
	free(cmds->cmd2);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		fd[2];
	t_cmds	*cmds;

	cmds = malloc(sizeof(t_cmds) * 1);
	if (!cmds)
		exit(0);
	i = 3;
	cmds = cmds_initializer(cmds, av, envp, 3);
	if (pipe(fd) == -1)
		exit(0);
	child_one(cmds, av[1], fd, envp);
	child_two(cmds, av[ac - 1], fd, envp);
	close(fd[0]);
	close(fd[1]);
	free_cmds(cmds);
	while (++i < ac - 1)
	{
		cmds = cmds_initializer(cmds, av, envp, i);
		pipe(fd);
	//	if (pipe(fd) == -1)
	//		exit(0);
		child_one(cmds, av[ac - 1], fd, envp);
		waitpid(cmds->pid1, NULL, 0);
		child_two(cmds, av[ac - 1], fd, envp);
		waitpid(cmds->pid2, NULL, 0);
		close(fd[0]);
		close(fd[1]);
		free_cmds(cmds);
	}
	free(cmds);
//	system("leaks -fullContent pipex");
	exit(0);
} 
