/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:55:33 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/22 14:34:50 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0 || !s)
		return ;
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	fill_tmp(t_ppx *ppx)
{
	char	*s;
	char	*limit;

	limit = ft_strjoin(ppx->limit, "\n");
	write(1, "heredoc> ", 9);
	s = get_next_line(0);
	while (s && ft_strcmp(s, limit))
	{
		ft_putstr_fd(s, ppx->fd1);
		free(s);
		write(1, "heredoc> ", 9);
		s = get_next_line(0);
	}
	if (s)
		free(s);
	free(limit);
	close(ppx->fd1);
	ppx->fd1 = open(".tmp", O_RDONLY, 0666);
}
