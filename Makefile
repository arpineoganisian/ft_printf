# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 21:14:08 by hwoodwri          #+#    #+#              #
#    Updated: 2020/12/07 21:36:08 by hwoodwri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFT_DIR = ./libft/

SRC = ft_printf.c \
	  parser.c \
	  structure.c \
	  ft_putchar_len.c \
	  type_c.c \
	  type_percent.c \
	  type_s.c \
	  type_d_i.c \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I.

RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	cp libft/libft.a ./libftprintf.a
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
%.o:%.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
