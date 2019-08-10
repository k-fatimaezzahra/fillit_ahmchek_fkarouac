# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkarouac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 18:45:37 by fkarouac          #+#    #+#              #
#    Updated: 2019/08/09 15:56:45 by ahmcherk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = *.c
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
		make -C libft
		gcc $(FLAGS) -o $(NAME) $(SRC) libft/libft.a

clean : 
		make clean -C libft

fclean : clean
		make fclean -C libft
		rm -rf $(NAME)

re : fclean all
