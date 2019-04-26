# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvirga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 23:31:55 by gvirga            #+#    #+#              #
#    Updated: 2018/08/27 21:48:04 by lpersin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc
CFLAGS:=-I./lib -Wall -Werror -Wextra
FILES:= main.c verif.c fill_tetri.c reader.c solve.c
LIBS:=lib/libft.a
OBJ:=$(FILES:%.c=%.o)
NAME:=fillit

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	cd ./lib && make
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)
	cd ./lib && make clean

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)
	cd ./lib && make fclean

.PHONY: re
re: fclean all
