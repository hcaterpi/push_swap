#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

// https://github.com/SamLynnEvans/Push_swap
// https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

// | sort | uniq -c
// https://www.youtube.com/watch?v=SLauY6PpjW4
// https://github.com/rizkyario/42-push_swap
// https://github.com/akhossanX/push_swap

// https://habr.com/ru/post/100990/
// http://algolist.manual.ru/
// https://habr.com/ru/company/ods/blog/322534/
// https://habr.com/ru/company/it-grad/blog/306214/

// https://github.com/VBrazhnik/Push_swap
// https://github.com/VBrazhnik/Push_swap/wiki/Algorithm

typedef struct s_list
{
	int				number;
	struct s_list   *next;
}			   t_list;

t_list	*ft_list_create(int number);
t_list	*ft_list_add(t_list **head, int number);
int		ft_list_size(t_list *head);
int		ft_list_find(t_list *head, int number);
void	ft_list_clear(t_list **head);

void    ft_swap(t_list **a, t_list **b);
void    ft_push(t_list **a, t_list **b);
void    ft_rotate(t_list **a, t_list **b);
void    ft_reverse_rotate(t_list **a, t_list **b);

#endif