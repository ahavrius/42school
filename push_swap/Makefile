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

FLAGS := -Wall -Werror -Wextra -Wall
NAME := push_swap

LIB_M := ./libft/Makefile
VISO_M := viso_push_swap
CHECK_M := checker

INC_DIR := ./incs/
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/

VIS_I := -I /usr/local/include
VIS_L := -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

SRC := checker.c display.c get_next_line.c main_checker.c  main_visual.c read_correct.c rect.c stack_change.c stack_init.c visual.c main_sort.c sort_part.c sort_rec.c stack_output.c sort_for_three.c three_sort_cases.c print_output.c sort.c read_with_args.c

SRC_MAIN := sort_part.c sort_rec.c stack_change.c stack_init.c read_correct.c main_sort.c stack_output.c sort_for_three.c three_sort_cases.c print_output.c sort.c read_with_args.c
SRC_CHECKER := checker.c get_next_line.c read_correct.c stack_change.c stack_init.c main_checker.c read_with_args.c
SRC_VISO := display.c main_visual.c rect.c visual.c checker.c get_next_line.c read_correct.c stack_change.c stack_init.c read_with_args.c

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): lib $(OBJ)
	gcc -o  $(NAME) $(addprefix $(OBJ_DIR), $(SRC_MAIN:.c=.o))  -L . -lft

check: lib $(OBJ)
	gcc -o  $(CHECK_M) $(addprefix $(OBJ_DIR), $(SRC_CHECKER:.c=.o))  -L . -lft

viso: lib $(OBJ)
	gcc -o  $(VISO_M) $(addprefix $(OBJ_DIR), $(SRC_VISO:.c=.o)) $(VIS_I) -L . -lft $(VIS_L)

$(OBJ_DIR)%.o: %.c
	gcc -c $< -o $@ -I $(INC_DIR)

lib:
	make -f $(LIB_M)

clean:
	@rm -f $(OBJ)
	make clean -f $(LIB_M)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(VISO_M)
	@rm -f $(CHECK_M)
	@rm -f libft.a
clean_all: clean
	@rm -f *~
re: fclean all

vpath %.c $(SRC_DIR)
