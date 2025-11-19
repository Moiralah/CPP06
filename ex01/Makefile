# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 15:38:23 by huidris           #+#    #+#              #
#    Updated: 2025/11/19 18:59:35 by huidris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= serialization

FLAGS	= -Wall -Wextra -Werror -std=c++98

CC		= c++

SRC		= main.cpp Serializer.cpp Data.cpp

$(NAME): $(SRC)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	clear

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
