# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 09:50:43 by jhotchki          #+#    #+#              #
#    Updated: 2024/01/04 09:50:46 by jhotchki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := checker

PUSH_SWAP_A := ../push_swap.a

LIBFT_A := ../libft/libft.a 

SRCS := checker.c get_next_line_utils.c get_next_line.c 

CFLAGS := -Wall -Wextra -Werror

CC := cc

OBS := $(SRCS:.c=.o)

MAKEFLAGS += --no-print-directory

.SILENT:

all: $(NAME)

$(NAME) : $(OBS) $(PUSH_SWAP_A) $(LIBFT_A)
	$(CC) $^ -o $(NAME)
	cp $(NAME) ../

$(PUSH_SWAP_A) :
	cd .. && make

$(LIBFT_A):
	cd ../libft && make

clean:
	rm -rf $(OBS) 

fclean: clean
	rm -rf $(NAME)
	 cd .. && rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
