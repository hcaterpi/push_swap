# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 14:26:54 by hcaterpi          #+#    #+#              #
#    Updated: 2020/02/05 21:15:40 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re

LIBFT = libft

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
					ft_sort.c

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)
	@echo 'Done'

$(LIBFT):
	@make -sC $(LIBFT)
	
$(OBJECTS): %.o : %.c push_swap.h
	@gcc -Wall -Wextra -Werror -c $<
 
$(NAME_CHECKER): $(LIBFT) $(OBJECTS) $(OBJECTS_CHECKER)
	@gcc -o $@ $(OBJECTS) $(OBJECTS_CHECKER) $(LIBFT)/$(LIBFT).a

$(OBJECTS_CHECKER): %.o : %.c push_swap.h
	@gcc -Wall -Wextra -Werror -c $<

$(NAME_PUSH_SWAP): $(LIBFT) $(OBJECTS) $(OBJECTS_PUSH_SWAP)
	@gcc -o $@ $(OBJECTS) $(OBJECTS_PUSH_SWAP) $(LIBFT)/$(LIBFT).a

$(OBJECTS_PUSH_SWAP): %.o : %.c push_swap.h
	@gcc -Wall -Wextra -Werror -c $<

clean:
	@make clean -sC $(LIBFT)
	@/bin/rm -f $(OBJECTS) $(OBJECTS_CHECKER) $(OBJECTS_PUSH_SWAP)

fclean: clean
	@make fclean -sC $(LIBFT)
	@/bin/rm -f $(NAME_CHECKER) $(NAME_PUSH_SWAP)

re: fclean all
