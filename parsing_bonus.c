/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:37:29 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/25 15:53:14 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files_bonus(t_ppx *ppx, int ac, char **av)
{
	if (!ppx->hd)
		ppx->fd1 = open(".tmp", O_CREAT | O_WRONLY, 0666);
	else
		ppx->fd1 = open(av[1], O_RDONLY);
	if (!ppx->hd)
		ppx->fd2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0666);
	else
		ppx->fd2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if ((!ppx->hd && ac != 6) || (ppx->hd && ac < 5)
		|| (!ppx->hd && !ppx->limit) || ppx->fd1 < 0 || ppx->fd2 < 0)
	{
		unlink(".tmp");
		unlink(av[ac - 1]);
		ft_error();
	}
}

void	check_cmds_bonus(t_ppx *ppx, char **av, int l)
{
	int	i;

	i = -1;
	while (++i < l)
	{
		if (ppx->hd == 0)
			ppx->cmds[i] = ft_strdup(av[i + 3]);
		else
			ppx->cmds[i] = ft_strdup(av[i + 2]);
		if (ppx->cmds[i][0] == '\0')
			ft_error();
	}
	ppx->cmds[i] = 0;
}

void	parsing_bonus(t_ppx *ppx, int ac, char *av[], char **env)
{
	int	i;
	int	l;

	if (ac < 5)
		ft_error();
	ppx->hd = ft_strncmp(av[1], "here_doc", 8);
	if (!ppx->hd)
		ppx->limit = ft_strdup(av[2]);
	open_files_bonus(ppx, ac, av);
	if (!ppx->hd)
		l = ac - 4;
	else
		l = ac - 3;
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
	check_cmds_bonus(ppx, av, l);
	check_paths(ppx);
}
