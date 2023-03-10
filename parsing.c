/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:37:29 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/25 15:53:36 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_ppx *ppx, int ac, char **av)
{
	ppx->fd1 = open(av[1], O_RDONLY);
	ppx->fd2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (ac != 5 || ppx->fd1 < 0 || ppx->fd2 < 0)
	{
		unlink(av[ac - 1]);
		ft_error();
	}
}

void	check_cmds(t_ppx *ppx, char **av, int l)
{
	int	i;

	i = -1;
	while (++i < l)
	{
		ppx->cmds[i] = ft_strdup(av[i + 2]);
		if (ppx->cmds[i][0] == '\0')
			ft_error();
	}
	ppx->cmds[i] = 0;
}

void	parsing(t_ppx *ppx, int ac, char *av[], char **env)
{
	int	i;
	int	l;

	if (ac < 5)
		ft_error();
	open_files(ppx, ac, av);
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
	check_cmds(ppx, av, l);
	check_paths(ppx);
}
