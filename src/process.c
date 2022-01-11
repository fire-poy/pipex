/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:50:00 by mpons             #+#    #+#             */
/*   Updated: 2022/01/11 22:48:21 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pipex.h"

int	proc_1(int fd[2][2], char **av, char **envp)
{
	if (dup2(fd[0][0], STDIN_FILENO) == -1)
		err_msg("dup child 1");
	if (dup2(fd[1][1], STDOUT_FILENO) == -1)
		err_msg("dup child 1");
	close (fd[0][1]);
	close (fd[1][0]);
	find_path(av[2], envp);
	return (0);
}

int	proc_2(int fd[2][2], char **av, char **envp)
{
	if (dup2(fd[1][0], STDIN_FILENO) == -1)
		err_msg("dup child 2");
	if (dup2(fd[0][1], STDOUT_FILENO) == -1)
		err_msg("dup child 2");
	close (fd[0][0]);
	close (fd[1][1]);
	find_path(av[3], envp);
	return (0);
}
