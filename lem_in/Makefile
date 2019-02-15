
FLAGS := -Werror -Wextra -Wall
NAME := lem_in

INC_DIR := ./incs/
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/

LIB_M := ./libft/Makefile

SRC := adding.c graph_operations.c parsing.c main.c

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc -o  $(NAME) $(OBJ) -L. -lft

lib:
	make -f $(LIB_M)

$(OBJ_DIR)%.o: %.c
	gcc -c $(FLAGS)  $< -o $@ -I $(INC_DIR)

clean:
	@rm -f $(OBJ)
	make -f $(LIB_M) clean
fclean: clean
	@rm -f $(NAME)
	make -f $(LIB_M) fclean
clean_all: clean
	@rm -f *~
re: fclean all

vpath %.c $(SRC_DIR)
