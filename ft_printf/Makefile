#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 11:12:22 by ahavrius          #+#    #+#              #
#    Updated: 2018/11/25 13:48:18 by ahavrius         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Werror -Wextra -Wall
NAME = libftprintf.a

I_DIR = ./includes
S_DIR = ./srcs


all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(S_DIR)/*.c -I $(I_DIR)
#	gcc -c main.c -I $(I_DIR)
	ar rc $(NAME) *.o
	gcc -o $(NAME) *.o

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
clean_all: clean
	rm -f *~
re: fclean all

db:
	gcc -g  *.c