/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:29:41 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/08 11:29:59 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_ismaxposition(t_list **stack, int number)
{
	t_list	*buffer;
	int		result;
	int		i;

	buffer = *stack;
	while (buffer)
	{
		if (buffer->number > number)
			return (0);
		buffer = buffer->next;
	}
	buffer = *stack;
	result = 0;
	i = 1;
	while (buffer && buffer->next)
	{
		if (buffer->number > buffer->next->number)
			result = i;
		buffer = buffer->next;
		i++;
	}
	return (result);
}

static int		ft_calc_position(t_list **stack, int number)
{
	t_list	*buffer;
	int		result;
	int		diff;
	int		i;

	if ((result = ft_ismaxposition(stack, number)))
		return (result);
	buffer = *stack;
	diff = 2147483647;
	i = 0;
	while (buffer)
	{
		if (number < buffer->number && diff > (buffer->number - number))
		{
			result = i;
			diff = buffer->number - number;
		}
		buffer = buffer->next;
		i++;
	}
	if (!buffer && diff == 2147483647)
		result = i;
	return (result);
}

static int		ft_calc_value(t_list **a, t_list **b, int order, int position)
{
	int		result;
	int		size_a;
	int		size_b;

	result = 0;
	size_a = ft_list_size(*a);
	size_b = ft_list_size(*b);
	if (order * 2 < size_b)
	{
		if (position * 2 <= size_a + 1)
			result = ft_max(order, position) + 1;
		else
			result = order + 1 + (size_a - position);
	}
	else
	{
		if (position * 2 < size_a + 1)
			result = (size_b - order) + 1 + position;
		else
			result = ft_max((size_a - position), (size_b - order)) + 1;
	}
	return (result);
}

t_number		ft_find_candidate(t_list **a, t_list **b)
{
	t_list		*buffer;
	t_number	candidate;
	int			position;
	int			value;
	int			i;

	i = 0;
	candidate.value = 2147483647;
	buffer = *b;
	while (buffer)
	{
		position = ft_calc_position(a, buffer->number);
		value = ft_calc_value(a, b, i, position);
		if (candidate.value > value)
		{
			candidate.order = i;
			candidate.position = position;
			candidate.value = value;
		}
		buffer = buffer->next;
		i++;
	}
	return (candidate);
}
