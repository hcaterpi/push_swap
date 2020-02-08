# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 14:26:54 by hcaterpi          #+#    #+#              #
#    Updated: 2020/02/08 17:35:09 by hcaterpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT = $(LIBFT_DIRECTORY)/libft.a
LIBFT_DIRECTORY = libft

INCLUDE = -I$(LIBFT_DIRECTORY)

INCLUDE_LIBRARY = -L$(LIBFT_DIRECTORY) -lft

SOURCE =	ft_common.c \
			ft_list.c \
			ft_stack.c

OBJECTS = $(SOURCE:.c=.o)

NAME_CHECKER = checker

OBJECTS_CHECKER = $(SOURCE_CHECKER:.c=.o)

SOURCE_CHECKER =	checker.c

NAME_PUSH_SWAP = push_swap

OBJECTS_PUSH_SWAP = $(SOURCE_PUSH_SWAP:.c=.o)

SOURCE_PUSH_SWAP =	push_swap.c \
					ft_insert.c \
					ft_search.c \
					ft_sort.c

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(LIBFT):
	make -C $(LIBFT_DIRECTORY)
	
$(OBJECTS): %.o : %.c push_swap.h
	$(CC) $(FLAGS) $(INCLUDE) -c $<

$(NAME_CHECKER): $(LIBFT) $(OBJECTS) $(OBJECTS_CHECKER)
	$(CC) $(FLAGS) $(INCLUDE_LIBRARY) -o $@ $(OBJECTS) $(OBJECTS_CHECKER)

$(OBJECTS_CHECKER): %.o : %.c push_swap.h
	$(CC) $(FLAGS) $(INCLUDE)  -c $<

$(NAME_PUSH_SWAP): $(LIBFT) $(OBJECTS) $(OBJECTS_PUSH_SWAP)
	$(CC) $(FLAGS) $(INCLUDE_LIBRARY) -o $@ $(OBJECTS) $(OBJECTS_PUSH_SWAP)

$(OBJECTS_PUSH_SWAP): %.o : %.c push_swap.h
	$(CC) $(FLAGS) $(INCLUDE) -c $<

clean:
	make clean -C $(LIBFT_DIRECTORY)
	/bin/rm -f $(OBJECTS) $(OBJECTS_CHECKER) $(OBJECTS_PUSH_SWAP) $(LIBFT)

fclean: clean
	/bin/rm -f $(NAME_CHECKER) $(NAME_PUSH_SWAP)

re: fclean all
