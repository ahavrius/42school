
FLAGS := -Werror -Wextra -Wall
NAME := ahavrius.filler

INC_DIR := ./incs/
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/

LIB_M := ./libft/Makefile
VISO_M := make.viso

SRC := distance.c get_next_line.c put_token.c get_data.c filler.c

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc -o  $(NAME) $(OBJ) -L. -lft

viso: lib
	make -f $(VISO_M)

lib:
	make -f $(LIB_M)

$(OBJ_DIR)%.o: %.c
	gcc -c $(FLAGS)  $< -o $@ -I $(INC_DIR)

clean:
	@rm -f $(OBJ)
	make -f $(LIB_M) clean
	make -f $(VISO_M) clean
fclean: clean
	@rm -f $(NAME)
	make -f $(LIB_M) fclean
	make -f $(VISO_M) fclean
clean_all: clean
	@rm -f *~
re: fclean all

vpath %.c $(SRC_DIR)


