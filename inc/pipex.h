/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:16:51 by mpons             #+#    #+#             */
/*   Updated: 2022/05/23 12:14:35 by mpons            ###   ########.fr       */
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
// # include <semaphore.h>

int		err_msg(char *err);
int		proc_1(int fd[2][2], char **av, char **envp);
int		proc_2(int fd[2][2], char **av, char **envp);
void	find_path(char *av, char **envp);
int		access(const char *path, int mode);
int		pipe(int pipefd[2]);
int		dup2(int oldfd, int newfd);
int		execve(const char *pathname, char *const argv[], char *const envp[]);
pid_t	fork(void);
pid_t	waitpid(pid_t pid, int *status, int options);

#endif
