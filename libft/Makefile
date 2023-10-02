# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 13:31:42 by lebarbos          #+#    #+#              #
#    Updated: 2023/08/16 18:57:20 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

LIB		= ar -rcs

RM		= rm -rf

DEPS 	= ../include

NAME	= libft.a

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_strncmp.c ft_memcmp.c ft_atoi.c \
			ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_memchr.c ft_strchr.c ft_strrchr.c \
			ft_strnstr.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS	= $(SRCS:.c=.o)

DEPS 	= ../include

BONUS_S	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c

BONUS_O	= $(BONUS_S:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS) 

bonus:		$(BONUS_O)
			$(LIB) $(NAME) $(BONUS_O) 

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
			$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re
