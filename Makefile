# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 14:26:54 by hcaterpi          #+#    #+#              #
#    Updated: 2020/01/31 01:30:01 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft objects clean fclean re

LIBFT = libft

NAME_CHECKER = checker

OBJECTS_CHECKER = $(SOURCE_CHECKER:.c=.o)

SOURCE_CHECKER =	checker.c \
					ft_list.c \
					ft_stack.c

all: libft $(NAME_CHECKER)

libft:
	@make -sC $(LIBFT)
 
$(NAME_CHECKER): $(OBJECTS_CHECKER)
	@gcc -o $@ $(OBJECTS_CHECKER) $(LIBFT)/$(LIBFT).a

$(OBJECTS_CHECKER): %.o : %.c push_swap.h
	@gcc -Wall -Wextra -Werror -c $<

clean:
	@make clean -sC $(LIBFT)
	@/bin/rm -f $(OBJECTS_CHECKER)

fclean: clean
	@make fclean -sC $(LIBFT)
	@/bin/rm -f $(NAME_CHECKER)

re: fclean all
