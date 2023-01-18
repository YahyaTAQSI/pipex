/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:37:29 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/18 18:50:57 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		while (ppx->paths[++j])
		{
			ppx->ftj = ft_strjoin(ppx->paths[j], ppx->fts);
			if (!access(ppx->ftj, F_OK | X_OK))
			{
				ppx->exe[i] = ft_strdup(ppx->ftj);
				cp++;
			}
			free(ppx->ftj);
		}
		free(ppx->fts);
		if (cp == 0)
			ft_error();
	}
	ppx->exe[i] = 0;
}

void	parsing(t_ppx *ppx, int ac, char *av[], char **env)
{
	int		i;

	ppx->fd1 = open(av[1], O_RDONLY);
	ppx->fd2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (ppx->fd1 < 0 || ppx->fd2 < 0)
		ft_error();
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			ppx->paths = ft_split_cmds(env[i] + 5, ':');
	}
	ppx->cmds = malloc((ac - 2) * sizeof(char *));
	ppx->exe = malloc((ac - 2) * sizeof(char *));
	if (!ppx->cmds || !ppx->exe)
		ft_error();
	i = -1;
	while (++i < ac - 3)
	{
		ppx->cmds[i] = ft_strdup(av[i + 2]);
		if (ppx->cmds[i][0] == '\0')
			ft_error();
	}
	ppx->cmds[i] = 0;
	check_paths(ppx);
}
