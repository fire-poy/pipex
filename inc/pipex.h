/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:16:51 by mpons             #+#    #+#             */
/*   Updated: 2022/01/11 22:51:49 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

int		err_msg(char *err);
int		proc_1(int fd[2][2], char **av, char **envp);
int		proc_2(int fd[2][2], char **av, char **envp);
void	find_path(char *av, char **envp);
int		access(const char *path, int mode);
int		unlink(const char *pathname);
int		pipe(int pipefd[2]);
pid_t	fork(void);
int		dup2(int oldfd, int newfd);
int		execve(const char *pathname, char *const argv[], char *const envp[]);
pid_t	wait(int *status);
pid_t	waitpid(pid_t pid, int *status, int options);

#endif
/*
typedef struct s_data
{
	pid_t	id[2];
    int		fd[2][2];
    int		i;
    int		e;
}	t_data;
*/
