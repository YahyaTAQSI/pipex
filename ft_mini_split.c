/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:38 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/25 13:37:37 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeall(t_ppx *p)
{
	if (p->cmds)
		freetwod(p->cmds);
	if (p->paths)
		freetwod(p->paths);
	if (p->exe)
		freetwod(p->exe);
}

void	freetwod(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	if_space(char *s, int *i, int *j)
{
	while (s[*i] && s[*i] == ' ')
	{
		(*i)++;
		(*j)++;
	}
}

char	*str(char	*s)
{
	int		l;
	int		i;
	int		j;
	char	*p;

	l = 0;
	i = 0;
	j = 0;
	if_space(s, &i, &j);
	while (s[i] && s[i] != ' ')
	{
		i++;
		l++;
	}
	p = malloc(l + 1);
	if (!p)
		ft_error();
	i = -1;
	while (++i < l)
		p[i] = s[i + j];
	p[i] = '\0';
	return (p);
}
