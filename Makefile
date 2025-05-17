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
./src/take_shortest.c \
./src/utils_2.c \
./src/utils.c 
  
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)

CC := cc

OBS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.SILENT:

all: libmake $(NAME)


$(NAME): $(ARCHIVE)
	$(CC) $< -L./libft -lft -o $@

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
