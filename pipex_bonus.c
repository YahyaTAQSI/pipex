/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:32:30 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/25 12:58:48 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char **env)
{
	t_ppx	ppx;

	ppx.hd = 1;
	parsing_bonus(&ppx, ac, av, env);
	if (!ppx.hd)
		fill_tmp(&ppx);
	exe_cmds(ppx, ac, env);
	freeall(&ppx);
	return (0);
}
