#include "push_swap.h"

void	ft_sort_triplet(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (first->number > second->number)
	{
		if (first->number > third->number && second->number > third->number)
		{
			ft_swap(stack, NULL);
			write(1, "sa\n", 3);
		}
		else if (first->number < third->number && second->number < third->number)
		{
			ft_swap(stack, NULL);
			write(1, "sa\n", 3);
		}
	}
	else
	{
		if (first->number < third->number && second->number > third->number)
		{
			ft_swap(stack, NULL);
			write(1, "sa\n", 3);
		}
	}
}

int			is_max(t_list **a, int number)
{
	t_list	*buffer;

	buffer = *a;
	while (buffer)
	{
		if (buffer->number > number)
			return (0);
		buffer = buffer->next;
	}
	return (1);
}

t_number	ft_find_candidate(t_list **a, t_list **b)
{
	t_list		*buffer_a, *buffer_b;
	t_number	candidate;
	int			size_a, size_b;
	int			i, j, position, diff, value;

	i = 0;
	candidate.value = __INT_MAX__;
	buffer_b = *b;
	size_a = ft_list_size(*a);
	size_b = ft_list_size(*b);
	while (buffer_b)
	{
		buffer_a = *a;
		j = 0;
		diff = __INT_MAX__;
		position = 0;
		if (is_max(a, buffer_b->number))
		{
			while (buffer_a && buffer_a->next)
			{
				if (buffer_a->number > buffer_a->next->number)
					position = j + 1;
				buffer_a = buffer_a->next;
				j++;
			}
		}
		else
		{
			while (buffer_a)
			{
				if (buffer_b->number < buffer_a->number
					&& diff > (buffer_a->number - buffer_b->number))
				{
					position = j;
					diff = buffer_a->number - buffer_b->number;
				}
				buffer_a = buffer_a->next;
				j++;
				if (!buffer_a && diff == __INT_MAX__)
				{
					position = j;
				}
			}
		}
		if (i * 2 < size_b)
		{
			if (position * 2 <= size_a + 1)
				value = ft_max(i, position) + 1;
			else
				value = i + 1 + (size_a - position);
		}
		else
		{
			if (position * 2 < size_a + 1)
				value = (size_b - i) + 1 + position;
			else
				value = ft_max((size_a - position), (size_b - i)) + 1;
		}
		if (candidate.value > value)
		{
			candidate.order = i;
			candidate.position = position;
			candidate.value = value;
		}
		buffer_b = buffer_b->next;
		i++;
	}
	return (candidate);
}

void		ft_insert_candidate(t_list **a, t_list **b, t_number candidate)
{
	int		size_a, size_b;
	int		i;

	size_a = ft_list_size(*a);
	size_b = ft_list_size(*b);
	if (candidate.order * 2 < size_b)
	{
		if (candidate.position * 2 < size_a + 1)
		{
			i = ft_min(candidate.order, candidate.position);
			while (i > 0)
			{
				ft_rotate(a, b);
				write(1, "rr\n", 3);
				i--;
			}
			if (candidate.order > candidate.position)
			{
				i = candidate.order - candidate.position;
				while (i > 0)
				{
					ft_rotate(b, NULL);
					write(1, "rb\n", 3);
					i--;
				}
			}
			else
			{
				i = candidate.position - candidate.order;
				while (i > 0)
				{
					ft_rotate(a, NULL);
					write(1, "ra\n", 3);
					i--;
				}
			}
			ft_push(b, a);
			write(1, "pa\n", 3);
		}
		else
		{
			i = candidate.order;
			while (i > 0)
			{
				ft_rotate(b, NULL);
				write(1, "rb\n", 3);
				i--;
			}
			i = size_a - candidate.position;
			while (i > 0)
			{
				ft_reverse_rotate(a, NULL);
				write(1, "rra\n", 4);
				i--;
			}
			ft_push(b, a);
			write(1, "pa\n", 3);
		}
	}
	else
	{
		if (candidate.position * 2 < size_a + 1)
		{
			i = size_b - candidate.order;
			while (i > 0)
			{
				ft_reverse_rotate(b, NULL);
				write(1, "rrb\n", 4);
				i--;
			}
			i = candidate.position;
			while (i > 0)
			{
				ft_rotate(a, NULL);
				write(1, "ra\n", 3);
				i--;
			}
			ft_push(b, a);
			write(1, "pa\n", 3);
		}
		else
		{
			i = ft_min(size_b - candidate.order, size_a - candidate.position);
			while (i > 0)
			{
				ft_reverse_rotate(a, b);
				write(1, "rrr\n", 4);
				i--;
			}
			if (size_b - candidate.order > size_a - candidate.position)
			{
				i = size_b - candidate.order - ft_min(candidate.order, size_a - candidate.position);
				while (i > 0)
				{
					ft_reverse_rotate(b, NULL);
					write(1, "rrb\n", 4);
					i--;
				}
			}
			else
			{
				i = size_a - candidate.position - ft_min(size_b - candidate.order, size_a - candidate.position);
				while (i > 0)
				{
					ft_reverse_rotate(a, NULL);
					write(1, "rra\n", 4);
					i--;
				}
			}
			ft_push(b, a);
			write(1, "pa\n", 3);
		}
	}
}

void	ft_normalize(t_list **a)
{
	t_list	*buffer;
	int		min, i, j;

	buffer = *a;
	min = buffer->number;
	j = 0;
	i = 0;
	while (buffer)
	{
		if (buffer->number < min)
		{
			min = buffer->number;
			j = i;
		}
		buffer = buffer->next;
		i++;
	}
	i = ft_list_size(*a);
	if (j * 2 < i)
	{
		while (j > 0)
		{
			ft_rotate(a, NULL);
			write(1, "ra\n", 3);
			j--;
		}
	}
	else
	{
		j = i - j;
		while (j > 0)
		{
			ft_reverse_rotate(a, NULL);
			write(1, "rra\n", 4);
			j--;
		}
	}
	
}

void	ft_sort(t_list **a, t_list **b)
{
	int			size_a;
	t_number	candidate;

	if (ft_issorted(a))
		return ;
	size_a = ft_list_size(*a);
	while (size_a > 3)
	{
		ft_push(a, b);
		write(1, "pb\n", 3);
		size_a--;
	}
	ft_sort_triplet(a);
	while (*b)
	{
		candidate = ft_find_candidate(a, b);
		ft_insert_candidate(a, b, candidate);
	}
	ft_normalize(a);
	return ;
}
