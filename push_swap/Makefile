#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 11:12:22 by ahavrius          #+#    #+#              #
#    Updated: 2018/12/24 15:03:50 by ahavrius         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS := -Wall
#-Werror -Wextra -Wall
NAME := checker

INC_DIR := ./incs/
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/

SRC := checker.c get_next_line.c read_correct.c stack_change.c stack_init.c

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o  $(NAME) $(OBJ)  -L . -lft

$(OBJ_DIR)%.o: %.c
	gcc -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
clean_all: clean
	@rm -f *~
re: fclean all

vpath %.c $(SRC_DIR)


