# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 14:26:54 by hcaterpi          #+#    #+#              #
#    Updated: 2020/02/12 15:55:02 by hcaterpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all objects clean fclean re

NAME = libft.a

OBJECTS = $(SOURCE:.c=.o)

SOURCE = 	ft_atoi.c \
			ft_catalog_add.c \
			ft_catalog_create.c \
			ft_catalog_delete.c \
			ft_catalog_find.c \
			ft_isinteger.c \
			ft_gnl.c \
			ft_max.c \
			ft_min.c \
			ft_putstr.c \
			ft_stradd.c \
			ft_strclean.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strnew.c \
			ft_strsplit.c \
			ft_strsub.c

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $^
	ranlib $(NAME)

$(OBJECTS): %.o : %.c libft.h
	gcc -Wall -Wextra -Werror -c $<

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(DIRECTORY)$(NAME)

re: fclean all
