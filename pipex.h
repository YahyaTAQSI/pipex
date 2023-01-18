/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:32:50 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/18 18:51:01 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_ppx
{
	char		**paths;
	char		**exe;
	char		**cmds;
	char		*fts;
	char		*ftj;
	int			fd1;
	int			fd2;
	int			i;
	int			fd[2];
	int			id;
}				t_ppx;

void	parsing(t_ppx *ppx, int ac, char *av[], char **env);
char	**ft_split(char const *s, char c);
char	**ft_split_cmds(char const *s, char c);

void	ft_error(void);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*str(char	*s);
void	exe_cmds(t_ppx	ppx, int ac, char **env);

#endif
