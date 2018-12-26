#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 11:12:22 by ahavrius          #+#    #+#              #
#    Updated: 2018/11/27 15:18:33 by ahavrius         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Werror -Wextra -Wall
NAME = libftprintf.a

INC_DIR = ./incs/
SRC_DIR = ./srcs/
OBJ_DIR = ./objs/

SRC = added.c check_mask.c double_added.c format_str.c ft_comf.c ft_printf.c ft_strchr.c ft_strcpy.c ft_strlen.c ft_strnew.c fun_double.c fun_num.c fun_str.c num_added.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_DIR)%.o: %.c
	gcc -c $< -I $(INC_DIR)

clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
clean_all: clean
	@rm -f *~
re: fclean all

vpath %.c $(SRC_DIR)


