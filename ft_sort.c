/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:30:23 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/08 11:30:45 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_sort_triplet(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (((first->number > second->number)
	&& ((first->number > third->number && second->number > third->number)
	|| (first->number < third->number && second->number < third->number)))
	|| (first->number < second->number && first->number < third->number
	&& second->number > third->number))
	{
		ft_swap(stack, NULL);
		write(1, "sa\n", 3);
	}
}

static int		ft_find_head(t_list **a)
{
	t_list	*buffer;
	int		current;
	int		result;
	int		i;

	buffer = *a;
	current = buffer->number;
	i = 0;
	while (buffer)
	{
		if (buffer->number < current)
		{
			current = buffer->number;
			result = i;
		}
		buffer = buffer->next;
		i++;
	}
	return (result);
}

static void		ft_normalize(t_list **a)
{
	int		head;
	int		size;

	head = ft_find_head(a);
	size = ft_list_size(*a);
	if (head * 2 < size)
	{
		while (head > 0 && head-- && !ft_rotate(a, NULL))
			write(1, "ra\n", 3);
	}
	else
	{
		head = size - head;
		while (head-- && !ft_reverse_rotate(a, NULL))
			write(1, "rra\n", 4);
	}
}

void			ft_sort(t_list **a, t_list **b)
{
	t_number	candidate;
	int			size;

	if (ft_issorted(a))
		return ;
	size = ft_list_size(*a);
	while (size > 3)
	{
		ft_push(a, b);
		write(1, "pb\n", 3);
		size--;
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
