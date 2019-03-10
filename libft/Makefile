#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsmith <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 19:16:24 by fsmith            #+#    #+#              #
#    Updated: 2018/12/01 19:16:26 by fsmith           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = *.c

INCLUDES = -I *.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(SRC) $(FLAGS)
	ar rc $(NAME) ft_*.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

main:
	gcc -o main $(INCLUDES) $(SRC) $(FLAGS)

mclean:
	/bin/rm -f main

remain:	mclean main