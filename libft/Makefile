# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 09:14:16 by jhotchki          #+#    #+#              #
#    Updated: 2023/09/23 07:43:08 by jhotchki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
	
SRCS := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
   	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

BONUS_SRCS := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c 

CFLAGS := -Wall -Wextra -Werror

CC := cc

OBS := $(SRCS:.c=.o)
BOBS := $(BONUS_SRCS:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBS)
	ar rcs $(NAME) $(OBS)

bonus: $(OBS) $(BOBS)
	ar rcs $(NAME) $(OBS) $(BOBS) 

clean:
	rm -rf $(OBS) $(BOBS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
