/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:55:43 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/20 14:32:20 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*checkstatic(char **tmp, char **res)
{
	ssize_t	len;

	len = checkline((*tmp));
	if ((*tmp) && (*tmp)[len] == '\n')
	{
		(*res) = (*tmp);
		(*tmp) = ft_strdup(&(*res)[len + 1]);
		(*res)[len + 1] = '\0';
		return ((*res));
	}
	else if ((*tmp))
	{
		if ((*tmp)[0])
			(*res) = ft_strmjoin((*res), (*tmp));
		free((*tmp));
		(*tmp) = NULL;
	}
	return (NULL);
}

char	*checkbuff(int fd, char **tmp, char **res, char **_9ra)
{
	ssize_t	len;

	len = read(fd, (*_9ra), 1);
	if (len > 0)
	{
		(*_9ra)[len] = '\0';
		len = checkline((*_9ra));
		if ((*_9ra)[len] == '\n')
		{
			*tmp = ft_strdup(&(*_9ra)[len + 1]);
			(*_9ra)[len + 1] = '\0';
			return (NULL);
		}
		else
			*res = ft_strmjoin(*res, *_9ra);
	}
	else
	{
		free(*_9ra);
		*_9ra = NULL;
		return (NULL);
	}
	return (*res);
}

void	freestrr(char *s)
{
	free(s);
	s = NULL;
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*res;
	char		*_9ra;

	if (fd < 0 || 1 <= 0)
		return (NULL);
	_9ra = (char *)malloc((1 + 1) * sizeof(char));
	if (!_9ra)
		return (NULL);
	res = NULL;
	while (1)
	{
		if (checkstatic(&tmp, &res))
			return (freestrr(_9ra), res);
		if (!checkbuff(fd, &tmp, &res, &_9ra))
			break ;
	}
	if (_9ra)
		res = ft_strmjoin(res, _9ra);
	return (freestrr(_9ra), res);
}
