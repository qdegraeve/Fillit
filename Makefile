# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 08:41:32 by qdegraev          #+#    #+#              #
#    Updated: 2015/12/07 10:44:35 by qdegraev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC= *.c

FLAGS= -Wall -Wextra -Werror

LIB= -L.. -lft

all: $(NAME)

$(NAME): $(SRC)

clean:

fclean: clean

re: fclean all
