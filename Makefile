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

ARCHIVE := push_swap.a

SRCS := free.c harmony_sort.c main.c num_utils.c push_swap.c push.c quicksort.c \
 return_utils.c reverse_rotate.c rotate.c route_6_and_targets.c routes.c \
 sort_utils.c sort.c swap.c take_shortest.c utils_2.c utils.c  
  
CFLAGS := -Wall -Wextra -Werror

CC := cc

OBS := $(SRCS:.c=.o)

all: libmake $(NAME)


$(NAME): $(ARCHIVE)
	$(CC) $< -L./libft -lft -o $@
	
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
