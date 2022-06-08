/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:31:50 by fde-albe          #+#    #+#             */
/*   Updated: 2022/06/08 16:22:47 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

void    check_commands(int ac, char **av, char **envp);
int 	ft_memcmp(const void *s1, const void *s2, size_t n);
char	**ft_split(char const *s, char c);
size_t  ft_strlen(const char *str);

#endif
