#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"		// исправить на "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	struct s_list   *next;
}			   t_list;

typedef struct s_number
{
	int				order;
	int				position;
	int				value;
}			   t_number;

t_list	*ft_list_create(int number);
t_list	*ft_list_add(t_list **head, int number);
int		ft_list_size(t_list *head);
int		ft_list_find(t_list *head, int number);
void	ft_list_clear(t_list **head);

void    ft_swap(t_list **a, t_list **b);
void    ft_push(t_list **a, t_list **b);
void    ft_rotate(t_list **a, t_list **b);
void    ft_reverse_rotate(t_list **a, t_list **b);

int		ft_issorted(t_list **head);
int		ft_clean(t_list **a, t_list **b, int command);

void	ft_sort(t_list **a, t_list **b);

#endif