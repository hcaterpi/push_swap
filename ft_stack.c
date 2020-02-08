/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:32:06 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/08 11:32:07 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_swap(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*second;
	t_list	**buffer;
	t_list	*buf;

	buffer = a;
	while (buffer && *buffer && (*buffer)->next)
	{
		buf = *buffer;
		first = buf->next;
		second = buf;
		buf->next = first->next;
		first->next = second;
		*buffer = first;
		if (buffer == a)
			buffer = b;
		else if (buffer == b)
			buffer = NULL;
	}
	return (0);
}

int		ft_push(t_list **a, t_list **b)
{
	t_list	*buffer;

	if (a && *a)
	{
		buffer = (*a)->next;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = buffer;
	}
	return (0);
}

int		ft_rotate(t_list **a, t_list **b)
{
	t_list	**buffer;
	t_list	*buf;

	buffer = a;
	while (buffer && *buffer && (*buffer)->next)
	{
		buf = *buffer;
		while (buf->next)
			buf = buf->next;
		buf->next = *buffer;
		buf = (*buffer)->next;
		(*buffer)->next = NULL;
		(*buffer) = buf;
		if (buffer == a)
			buffer = b;
		else if (buffer == b)
			buffer = NULL;
	}
	return (0);
}

int		ft_reverse_rotate(t_list **a, t_list **b)
{
	t_list	*current;
	t_list	*previous;
	t_list	**buffer;
	t_list	*buf;

	buffer = a;
	while (buffer && *buffer && (*buffer)->next)
	{
		buf = *buffer;
		current = buf;
		while (current->next)
		{
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		current->next = buf;
		(*buffer) = current;
		if (buffer == a)
			buffer = b;
		else if (buffer == b)
			buffer = NULL;
	}
	return (0);
}
