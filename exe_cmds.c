/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:37:06 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/25 14:18:30 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_ppx ppx, char **env)
{
	char	**s;

	s = ft_split(ppx.cmds[ppx.i], ' ');
	close(ppx.fd[1]);
	close(ppx.fd[0]);
	execve(ppx.exe[ppx.i], s, env);
	freetwod(s);
}

void	if_child(t_ppx ppx, int ac, char **env)
{
	if (ppx.id == 0)
	{
		if (ppx.i == 0)
		{
			if (dup2(ppx.fd1, 0) < 0)
				ft_error();
		}
		if (!ppx.hd && ppx.i == ac - 5)
		{
			if (dup2(ppx.fd2, 1) < 0)
				ft_error();
		}
		else if (ppx.hd && ppx.i == ac - 4)
		{
			if (dup2(ppx.fd2, 1) < 0)
				ft_error();
		}
		else
		{
			if (dup2(ppx.fd[1], 1) < 0)
				ft_error();
		}
		exec(ppx, env);
	}
}

void	exe_cmds(t_ppx ppx, int ac, char **env)
{
	ppx.i = -1;
	while (ppx.cmds[++ppx.i])
	{
		if (pipe(ppx.fd) < 0)
			ft_error();
		ppx.id = fork();
		if (ppx.id < 0)
			ft_error();
		if_child(ppx, ac, env);
		if (dup2(ppx.fd[0], 0) < 0)
			ft_error();
		close(ppx.fd[1]);
		close(ppx.fd[0]);
	}
	while (1)
	{
		if (wait(NULL) == -1)
			break ;
	}
	unlink(".tmp");
}

void	check_pts(t_ppx *ppx, int i, int j, int *cp)
{
	if (ppx->fts[0] == '.' || ppx->fts[0] == '/')
	{
		ppx->exe[i] = ft_strdup(ppx->fts);
		(*cp)++;
		return ;
	}
	while (ppx->paths[++j])
	{
		ppx->ftj = ft_strjoin(ppx->paths[j], ppx->fts);
		if (!access(ppx->ftj, F_OK))
		{
			ppx->exe[i] = ft_strdup(ppx->ftj);
			(*cp)++;
		}
		free(ppx->ftj);
	}
}

void	check_paths(t_ppx *ppx)
{
	int	i;
	int	j;
	int	cp;

	i = -1;
	while (ppx->cmds[++i])
	{
		cp = 0;
		j = -1;
		ppx->fts = str(ppx->cmds[i]);
		if (ppx->fts[0] == '\0')
			ft_error();
		check_pts(ppx, i, j, &cp);
		free(ppx->fts);
		if (cp == 0)
			ft_error();
	}
	ppx->exe[i] = 0;
}
