# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkarouac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 18:45:37 by fkarouac          #+#    #+#              #
#    Updated: 2019/07/30 18:52:51 by fkarouac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = *.c
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
		make -C libft
		gcc $(FLAGS) -o $(NAME) libft/libft.a

clean : 
		make -c clean libft

fclean : clean
		make -c fclean libft
		rm -rf $(NAME)

re : fclean all
