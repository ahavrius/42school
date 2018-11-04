#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 14:49:04 by ahavrius          #+#    #+#              #
#    Updated: 2018/10/28 12:17:19 by ahavrius         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FLAG_NEW = -std = c99

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) *.c
	ar rc $(NAME) *.o

clean:
	rm -f *.o

clean_all: clean
	rm -f *~
	rm -f .#*
	rm -f "#*#"

fclean: clean
	rm -f $(NAME)

re: fclean all