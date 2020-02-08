# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 14:26:54 by hcaterpi          #+#    #+#              #
#    Updated: 2020/02/08 13:43:32 by hcaterpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT = libft

INCLUDE = -I$(LIBFT)

INCLUDE_LIBRARY = -L. -lft

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
	make -C $(LIBFT)
	
$(OBJECTS): %.o : %.c push_swap.h
	$(CC) $(FLAGS) $(INCLUDE) -c $<

$(NAME_CHECKER): $(OBJECTS) $(OBJECTS_CHECKER) | $(LIBFT)
	$(CC) $(FLAGS) $(INCLUDE_LIBRARY) -o $@ $^

$(OBJECTS_CHECKER): %.o : %.c push_swap.h
	$(CC) $(FLAGS) $(INCLUDE)  -c $<

$(NAME_PUSH_SWAP): $(OBJECTS) $(OBJECTS_PUSH_SWAP) | $(LIBFT)
	$(CC) $(FLAGS) $(INCLUDE_LIBRARY) -o $@ $^

$(OBJECTS_PUSH_SWAP): %.o : %.c push_swap.h
	$(CC) $(FLAGS) $(INCLUDE) -c $<

clean:
	make clean -C $(LIBFT)
	/bin/rm -f $(OBJECTS) $(OBJECTS_CHECKER) $(OBJECTS_PUSH_SWAP) $(LIBFT).a

fclean: clean
	/bin/rm -f $(NAME_CHECKER) $(NAME_PUSH_SWAP)

re: fclean all
