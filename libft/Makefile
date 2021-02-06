# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 13:59:44 by almarsel          #+#    #+#              #
#    Updated: 2020/10/10 07:18:41 by almarsel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Werror -Wextra

SRCS = ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c		\
		ft_memccpy.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strmapi.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_putchar.c	\
		ft_str_tolower.c\
		ft_uitoa_base.c	\
		ft_ulltoa_base.c

OBJET = $(SRCS:.c=.o)
INCLUDE = libft.h

all : $(NAME)

$(NAME): $(OBJET) $(INCLUDE)
	ar -rc $(NAME) $(OBJET)
	ranlib $(NAME)

%.o: %.c
	@gcc $(FLAG) -c $< $(INCLUDE)

clean :
	rm -f $(OBJET)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
