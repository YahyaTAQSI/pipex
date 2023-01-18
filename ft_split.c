/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:13:32 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/18 12:42:31 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	strll(char *s, char c)
{
	int	i;
	int	cp;

	cp = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			cp++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cp);
}

static char	*ft_strndup(char *s, int l)
{
	char	*p;
	int		i;

	p = (char *) malloc((l + 1) * sizeof(char));
	if (!p)
		ft_error();
	i = 0;
	while (i < l)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void	removeleaks(char **p)
{
	int	i;

	i = -1;
	while (p[++i])
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;
}

static void	fills(char *s, char c, int l, char **p)
{
	int	i;
	int	j;
	int	cp;

	i = -1;
	j = 0;
	while (++i < l)
	{
		cp = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			cp++;
			j++;
		}
		p[i] = ft_strndup(&s[j - cp], cp);
		if (p[i] == NULL || p[i] == '\0')
		{
			removeleaks(p);
			return ;
		}
		j++;
	}
	p[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		l;
	char	**p;

	if (!s)
		ft_error();
	l = strll((char *)s, c);
	p = (char **)malloc((l + 1) * sizeof(char *));
	if (!p)
		ft_error();
	fills((char *)s, c, l, p);
	return (p);
}
