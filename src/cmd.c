/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:50:30 by mpons             #+#    #+#             */
/*   Updated: 2022/01/13 15:59:09 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		tab[i] = NULL;
		i++;
	}
	free (tab);
	tab = NULL;
}

void	find_path(char *av, char **envp)
{
	char	**paths;
	char	**cmd_tab;
	int		i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	cmd_tab = ft_split(av, ' ');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], cmd_tab[0]);
		if (access(paths[i], 0) == 0)
			execve(paths[i], cmd_tab, envp);
		free (paths[i]);
		i++;
	}	
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(cmd_tab[0], 2);
	free_tab (cmd_tab);
	exit (1);
}
//	execve("usr/bin/" , cmd_tab, envp);
