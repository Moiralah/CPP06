# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 15:38:23 by huidris           #+#    #+#              #
#    Updated: 2025/11/18 00:16:43 by huidris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= convert

FLAGS	= -Wall -Wextra -Werror -std=c++98

CC		= c++

SRC		= main.cpp ScalarConverter.cpp

$(NAME): $(SRC)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	clear

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
