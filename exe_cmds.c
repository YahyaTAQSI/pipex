/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:37:06 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/18 18:46:43 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	if_child(t_ppx ppx, int ac, char **env)
{
	if (ppx.id == 0)
	{
		if (ppx.i == 0)
			dup2(ppx.fd1, 0);
		if (ppx.i == ac - 4)
			dup2(ppx.fd2, 1);
		else
			dup2(ppx.fd[1], 1);
		close(ppx.fd[1]);
		close(ppx.fd[0]);
		execve(ppx.exe[ppx.i], ft_split(ppx.cmds[ppx.i], ' '), env);
	}
}

void	exe_cmds(t_ppx ppx, int ac, char **env)
{
	ppx.i = -1;
	while (++ppx.i < ac - 3)
	{
		if (ppx.i != ac - 4)
		{
			if (pipe(ppx.fd) < 0)
				ft_error();
		}
		ppx.id = fork();
		if (ppx.id < 0)
			ft_error();
		if_child(ppx, ac, env);
		dup2(ppx.fd[0], 0);
		close(ppx.fd[1]);
		close(ppx.fd[0]);
		wait(NULL);
	}
}
