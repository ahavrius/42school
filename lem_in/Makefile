
FLAGS := -Werror -Wextra -Wall
NAME := lem-in

INC_DIR := -I ./incs/
INC_DIR_LIB := -I ./libft/

SRC_DIR := ./resources/
OBJ_DIR := ./objs/

LIB_M := ./libft/Makefile

SRC := graph_operations.c parsing.c main.c bfs.c path_manager.c efficiency.c recurse.c print_res.c special_case.c

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc  -o $(NAME) $(OBJ) -L. -lft

lib:
	make -f $(LIB_M)

$(OBJ_DIR)%.o: %.c
	gcc -c $(FLAGS)  $< -o $@  $(INC_DIR) $(INC_DIR_LIB)

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
