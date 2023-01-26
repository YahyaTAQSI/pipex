# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 12:46:52 by ytaqsi            #+#    #+#              #
#    Updated: 2023/01/24 18:25:22 by ytaqsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
FRM = rm -rf

NAME = pipex
BONUS = pipex_bonus
HEADER = pipex.h

SRCMAN = ft_mini_split.c \
		ft_split_cmds.c \
		ft_split.c \
		exe_cmds.c \
		parsing.c \
		pipex.c \
		utils.c \

SRCBON = ft_mini_split.c \
		ft_split_cmds.c \
		ft_split.c \
		exe_cmds.c \
		parsing_bonus.c \
		pipex_bonus.c \
		utils.c \
		get_next_line.c \
		fill_tmp.c \
		get_next_line_utils.c \

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(SRCMAN) $(HEADER)
	$(CC) $(CFLAGS) $(SRCMAN) -o $(NAME)

$(BONUS): $(SRCBON) $(HEADER)
	$(CC) $(CFLAGS) $(SRCBON) -o $(BONUS)

clean:
	$(FRM) $(NAME)

fclean: clean
	$(FRM) $(BONUS)

re: fclean all
