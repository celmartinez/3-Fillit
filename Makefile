# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awilk <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/19 19:19:24 by awilk             #+#    #+#              #
#    Updated: 2018/01/25 17:51:57 by awilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = fillit

SRC_NAME = form_is_valide.c\
		   ft_create_buf.c\
		   ft_fill_map.c\
		   ft_tetritab.c\
		   ft_show_map.c\
		   tetri_is_valide.c\
		   main.c\
		   libft/ft_putendl.c\
		   libft/ft_strdel.c\

OBJ_PATH = .

LDFLAGS = -Llibft

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $<

clean: 
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true 

fclean: clean 
	rm -fv $(NAME)

re: fclean all

.PHONY: all, cleanm fclean, re

norme: 
	norminette $(SRC)
	norminette $(INC_PATH)*.h

