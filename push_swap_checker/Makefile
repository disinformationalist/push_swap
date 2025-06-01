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

COLOR_RESET = \033[0m
COLOR_GREEN = \033[1;92m
COLOR_BLUE = \033[1;96m 


define print_colored
	@echo "$(COLOR_GREEN)$(1)$(COLOR_BLUE)$(2)$(COLOR_RESET)$(3)"
endef

.SILENT:

all: $(NAME)

$(NAME) : $(OBS) $(PUSH_SWAP_A) $(LIBFT_A)
	$(CC) $^ -o $(NAME)
	cp $(NAME) ../
	$(call print_colored, "[SUCCESS]", "./$(NAME)", "Ready")

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
