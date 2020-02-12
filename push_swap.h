/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:33:23 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/12 18:42:37 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int				number;
	struct s_list	*next;
}				t_list;

typedef struct	s_number
{
	int				order;
	int				position;
	int				value;
}				t_number;

t_list			*ft_list_add(t_list **head, int number);
int				ft_list_size(t_list *head);
int				ft_list_find(t_list *head, int number);
void			ft_list_clear(t_list **head);

int				ft_swap(t_list **a, t_list **b);
int				ft_push(t_list **a, t_list **b);
int				ft_rotate(t_list **a, t_list **b);
int				ft_reverse_rotate(t_list **a, t_list **b);

int				ft_issorted(t_list **head);
int				ft_input(int ac, char **av, t_list **a);
int				ft_clean(t_list **a, t_list **b, int command);

t_list			*ft_find_sequence(t_list **a);
t_number		ft_find_candidate(t_list **a, t_list **b);
void			ft_insert_candidate(t_list **a, t_list **b,
				t_number candidate, char **result);
char			*ft_base_sort(t_list **a, t_list **b);
char			*ft_optimized_sort(t_list **a, t_list **b);
void			ft_sort(t_list **a, t_list **b);

#endif
