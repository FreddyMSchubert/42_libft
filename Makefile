# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 10:17:52 by fschuber          #+#    #+#              #
#    Updated: 2023/10/13 08:36:25 by fschuber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
BONUS_NAME	=	lstlibft.a

SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_itoa.c ft_substr.c ft_tolower.c ft_toupper.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \

BONUS_SRCS	=	ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
				ft_lstadd_front.c ft_lstnew.c ft_lstsize.c \

OBJS = $(SRCS:.c=.o)					# SRCS -> OBJS NAMING SCHEME
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc								# COMPILER
CFLAGS = -Wall -Wextra -Werror -I.		# FLAGS

$(NAME): $(OBJS)						# LIB CREATION DEPENDS ON OBJS
	ar rcs $(NAME) $(OBJS)
$(BONUS_NAME): $(BONUS_OBJS)
	ar rcs $(BONUS_NAME) $(BONUS_OBJS)

%.o: %.c								# FOR EVERY OBJ THERES A SRC FILE
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

all: $(NAME)

bonus: $(BONUS_NAME)