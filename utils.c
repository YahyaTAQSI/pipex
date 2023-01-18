/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:41:45 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/18 17:52:34 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		is1;
	int		is2;
	char	*p;

	is1 = ft_strlen(s1);
	is2 = ft_strlen(s2);
	p = (char *)malloc((is1 + is2 + 1) * sizeof(char));
	if (!p)
		ft_error();
	is1 = 0;
	is2 = 0;
	while (s1 && s1[is1])
	{
		p[is1] = s1[is1];
		is1++;
	}
	while (s2[is2])
		p[is1++] = s2[is2++];
	p[is1] = '\0';
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	while (s[i])
		i++;
	p = (char *) malloc((i + 1) * sizeof(char));
	if (!p)
		ft_error();
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
