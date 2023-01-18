# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 12:46:52 by ytaqsi            #+#    #+#              #
#    Updated: 2023/01/18 17:38:31 by ytaqsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
# CFLAGS = -Wall -Wextra -Werror
FRM = rm -rf

NAME = pipex
HEADER = pipex.h

SRCMAN = ft_mini_split.c \
		ft_split_cmds.c \
		ft_split.c \
		exe_cmds.c \
		parsing.c \
		pipex.c \
		utils.c \

all: $(NAME)

$(NAME): $(SRCMAN) $(HEADER)
	$(CC) $(CFLAGS) $(SRCMAN) -o $(NAME)

clean:
	$(FRM) $(NAME)

fclean: clean
	$(FRM) $(BONUS)

re: fclean all
