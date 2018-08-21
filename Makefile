#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddryha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/08 18:08:05 by ddryha            #+#    #+#              #
#    Updated: 2018/05/08 18:08:05 by ddryha           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in
FLAGS = -Wall -Wextra -Werror
HEAD = -I.includes
LIB = ./libft
SRC := srcs/lem_in.c \
		srcs/ft_save_rooms.c \
		srcs/ft_extra_func.c \
		srcs/ft_breadth_first_search.c \
		srcs/ft_depth_first_search.c \
		srcs/ft_ant_farm.c \
		srcs/ft_exec_flg.c \
		srcs/ft_del_error.c \
		srcs/ft_free.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	gcc $(FLAGS) $(OBJ) $(LIB)/libftprintf.a $(HEAD) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $(HEAD) -c $< -o $@

clean:
	make clean -C $(LIB)
	@rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
