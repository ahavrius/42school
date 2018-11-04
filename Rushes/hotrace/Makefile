#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/03 23:01:08 by ahavrius          #+#    #+#              #
#    Updated: 2018/11/03 23:01:10 by ahavrius         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = hotrace
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) *.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all