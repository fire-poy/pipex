/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:03:39 by mpons             #+#    #+#             */
/*   Updated: 2022/01/11 23:13:30 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pipex.h"

int	err_msg(char *err)
{
	perror(err);
	exit (1);
	return (1);
}

void	forking(pid_t id[2])
{
	int	i;

	i = 0;
	while (i < 2)
	{
		id[i] = fork();
		if (id[i] == -1)
			err_msg("fork error");
		if (id[i] == 0)
			break ;
		i++;
	}
}

void	close_and_wait(int fd[2][2], pid_t id[2])
{
	close (fd[1][0]);
	close (fd[1][1]);
	waitpid(id[0], NULL, 0);
	waitpid(id[1], NULL, 0);
	close (fd[0][0]);
	close (fd[0][1]);
}
//	while (wait(NULL) != -1);

int	main(int ac, char **av, char **envp)
{
	pid_t	id[2];
	int		fd[2][2];

	if (ac != 5)
		return (err_msg("invalid number of arguments"));
	fd[0][0] = open(av[1], O_RDONLY);
	fd[0][1] = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd[0][0] < 0)
		return (err_msg("infile"));
	if (fd[0][1] < 0)
		return (err_msg("outfile"));
	if (pipe(fd[1]) == -1)
		err_msg("pipe error");
	forking(id);
	if (id[0] == 0)
		proc_1(fd, av, envp);
	if (id[1] == 0)
		proc_2(fd, av, envp);
	if (id[0] != 0 && id[1] != 0)
		close_and_wait(fd, id);
	return (0);
}
