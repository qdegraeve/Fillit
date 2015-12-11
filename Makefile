# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 08:41:32 by qdegraev          #+#    #+#              #
#    Updated: 2015/12/11 08:30:21 by qdegraev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC= 1record_check_file.c 2make_pieces.c ft_lstlen.c ft_small_square.c ft_taballoc.c main.c list.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -L. -lft -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
