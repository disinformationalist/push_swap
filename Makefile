# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 09:45:44 by jhotchki          #+#    #+#              #
#    Updated: 2024/01/04 09:45:47 by jhotchki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRC_DIR = ./src

OBJ_DIR = ./obj

INC_DIR = ./inc

ARCHIVE := push_swap.a

SRCS := ./src/free.c \
./src/harmony_sort.c \
./src/main.c \
./src/num_utils.c \
./src/push_swap.c \
./src/push.c \
./src/quicksort.c \
./src/return_utils.c \
./src/reverse_rotate.c \
./src/rotate.c \
./src/route_6_and_targets.c \
./src/routes.c \
./src/sort_utils.c \
./src/sort.c \
./src/swap.c \
./src/swap_test.c \
./src/hard_codes.c \
./src/take_shortest.c \
./src/utils_2.c \
./src/utils.c 
  
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)

CC := cc

OBS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MAKEFLAGS += --no-print-directory

COLOR_RESET = \033[0m
COLOR_GREEN = \033[1;92m
COLOR_BLUE = \033[1;96m 


define print_colored
	@echo "$(COLOR_GREEN)$(1)$(COLOR_BLUE)$(2)$(COLOR_RESET)$(3)"
endef

MAKEFLAGS += --no-print-directory

.SILENT:

all: libmake $(NAME)

$(NAME): $(ARCHIVE)
	$(CC) $< -L./libft -lft -o $@
	$(call print_colored, "[SUCCESS]", "./$(NAME)", "Ready")

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(ARCHIVE): $(OBS)
	ar rcs $(ARCHIVE) $(OBS)

libmake:
	cd libft && make

bonus:
	cd push_swap_checker && make

clean:
	rm -rf $(OBS)
	cd libft && make clean

fclean: clean libfclean
	rm -rf $(NAME)
	rm -rf $(ARCHIVE)
	cd push_swap_checker && make fclean
	
libfclean:
	cd libft && make fclean

checkerclean:
	cd push_swap_checker && make clean

re: fclean all

.PHONY: all clean fclean re
