#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 19:22:16 by ahavrius          #+#    #+#              #
#    Updated: 2018/10/22 19:32:08 by ahavrius         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
INC = ./includes
OBS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
FLAGS = -Wall -Wextra -Werror
all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(SRC) -I $(INC)
	ar rc $(NAME) *.o

clean :
	rm -f *.o

fclean : clean
	rm $(NAME)

re: fclean all