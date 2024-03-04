# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: freddy <freddy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 10:17:52 by fschuber          #+#    #+#              #
#    Updated: 2024/03/04 12:27:14 by freddy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_itoa.c ft_substr.c ft_tolower.c ft_toupper.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c

BONUS_SRCS	=	ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
				ft_lstadd_front.c ft_lstnew.c ft_lstsize.c \

# Added after the project was finished, for future projects
XTRA_SRCS	=	ft_free_utils.c ft_strarrdup.c ft_isnbr.c ft_isspace.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
XTRA_OBJS = $(XTRA_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
xtra: $(XTRA_OBJS)
	ar rcs $(NAME) $(XTRA_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -f $(XTRA_OBJS)
fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f $(XTRA_NAME)
comp: all bonus xtra clean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re bonus