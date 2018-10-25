# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 13:49:55 by vomelchu          #+#    #+#              #
#    Updated: 2018/04/21 15:00:46 by vomelchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAG = -c -Wall -Werror -Wextra
SRC_NAME = ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memccpy.c \
		   ft_memmove.c \
		   ft_memcmp.c \
		   ft_memchr.c \
		   ft_strlen.c \
		   ft_strdup.c \
	 	   ft_strcpy.c \
	 	   ft_strncpy.c \
	 	   ft_strcat.c \
	 	   ft_strncat.c \
		   ft_strlcat.c \
		   ft_strchr.c \
	 	   ft_strrchr.c \
	 	   ft_strstr.c \
	 	   ft_strnstr.c \
		   ft_strcmp.c \
		   ft_strncmp.c \
	 	   ft_atoi.c \
	 	   ft_isalpha.c \
	 	   ft_isdigit.c \
	 	   ft_isalnum.c \
	 	   ft_isascii.c \
	 	   ft_isprint.c \
		   ft_toupper.c \
	 	   ft_tolower.c \
	 	   ft_memalloc.c \
		   ft_memdel.c \
		   ft_strnew.c \
		   ft_strdel.c \
	 	   ft_strclr.c \
	 	   ft_striter.c \
	 	   ft_striteri.c \
	 	   ft_strmap.c \
	 	   ft_strmapi.c \
	 	   ft_strequ.c \
	 	   ft_strnequ.c \
	 	   ft_strsub.c \
	 	   ft_strjoin.c \
		   ft_strtrim.c	\
		   ft_strsplit.c \
	 	   ft_itoa.c \
		   ft_putchar.c \
	 	   ft_putstr.c \
		   ft_putendl.c \
	 	   ft_putnbr.c \
	 	   ft_putchar_fd.c \
		   ft_putstr_fd.c \
	 	   ft_putendl_fd.c \
	 	   ft_putnbr_fd.c \
		   ft_lstnew.c \
		   ft_lstdelone.c \
		   ft_lstdel.c \
		   ft_lstadd.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_fibonacci.c \
		   ft_power.c \
		   ft_sepereteword.c \
		   ft_sqrt.c \
		   ft_strnewword.c

OBJ_NAME = $(SRC_NAME:.c=.o)
AR = ar rc
RLIB = ranlib
HDR = -I ./includes/libft.h
RM = rm -f

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAG) $(SRC_NAME)
	@$(AR) $(NAME) $(OBJ_NAME)
	@$(RLIB) $(NAME)

clean:
	@$(RM) $(OBJ_NAME)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
