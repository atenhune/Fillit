# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antti <antti@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 12:00:52 by plehtika          #+#    #+#              #
#    Updated: 2022/01/18 19:43:28 by antti            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = ./

INCLUDES = ./libft/

SRCS = main make_sqr support validate_map

LIB_NAME = libft.a

LIB_PATH = ./libft/

LIB_SRCS = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy \
strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp \
atoi isalpha isdigit isalnum isascii isprint toupper tolower \
memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ \
strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr \
putchar_fd putstr_fd putendl_fd putnbr_fd lstnew lstdelone lstdel lstadd \
lstiter lstmap lstappend strstretch delarray

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(patsubst %,$(LIB_PATH)ft_%.c,$(LIB_SRCS)) -I$(INCLUDES) $(CFLAG)
	ar -rcs $(LIB_NAME) $(patsubst %,./ft_%.o,$(LIB_SRCS))
	gcc -o $(NAME) $(patsubst %,$(SRC_PATH)%.c,$(SRCS)) -I$(INCLUDES) -L. -lft $(CFLAG)

clean:
	rm -f $(patsubst %,./ft_%.o,$(LIB_SRCS))

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re