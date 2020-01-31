#include "push_swap.h"

static int		ft_distributor(t_list **a, t_list **b, char *command)
{
	if (ft_strequ(command, "sa"))
		ft_swap(a, NULL);
	else if (ft_strequ(command, "sb"))
		ft_swap(b, NULL);
	else if (ft_strequ(command, "ss"))
		ft_swap(a, b);
	else if (ft_strequ(command, "pa"))
		ft_push(b, a);
	else if (ft_strequ(command, "pb"))
		ft_push(a, b);
	else if (ft_strequ(command, "ra"))
		ft_rotate(a, NULL);
	else if (ft_strequ(command, "rb"))
		ft_rotate(b, NULL);
	else if (ft_strequ(command, "rr"))
		ft_rotate(a, b);
	else if (ft_strequ(command, "rra"))
		ft_reverse_rotate(a, NULL);
	else if (ft_strequ(command, "rrb"))
		ft_reverse_rotate(b, NULL);
	else if (ft_strequ(command, "rrr"))
		ft_reverse_rotate(a, b);
	else	
		return (1);
	return (0);
}

static int		ft_issorted(t_list *head)
{
	t_list	*buffer;

	buffer = head;
	while (head && head->next)
	{
		head = head->next;
		if (buffer->number > head->number)
			return (0);
	}
	return (1);
}

static int		ft_clean(t_list **a, t_list **b, int command)
{
	if (command == 1)
		write(1, "Error\n", 6);
	ft_list_clear(a);
	ft_list_clear(b);
	return (command);
}

int	 			main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*buffer;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	while (++i < argc)
	{
		if (ft_isinteger(argv[i]) && !ft_list_find(a, ft_atoi(argv[i])))
			ft_list_add(&a, ft_atoi(argv[i]));
		else
			return (ft_clean(&a, &b, 1));
	}
	while (ft_gnl(0, &buffer) > 0)
	{
		if (ft_distributor(&a, &b, buffer))
			return (ft_clean(&a, &b, 1));
	}
	if (ft_issorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_clean(&a, &b, 0));
}
