/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:55:37 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/20 13:57:45 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strmjoin(char *s1, char *s2)
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
	free(s1);
	s1 = NULL;
	return (p);
}

ssize_t	checkline(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (i);
}
