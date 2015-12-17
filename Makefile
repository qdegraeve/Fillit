# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 08:41:32 by qdegraev          #+#    #+#              #
#    Updated: 2015/12/17 17:11:37 by afillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBPATH = libft
LIB = $(LIBPATH)/libft.a

NAME= fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft

LDFLAGS = -L libft -lft

SRC = \
	0main.c \
	1record_check_file.c \
	2make_pieces.c \
	ft_lstlen.c \
	ft_small_square.c \
	ft_taballoc.c \
	3list.c \
	ft_fill_board.c \
	ft_free.c

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	make -C $(LIBPATH)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBPATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBPATH)

re: fclean all
