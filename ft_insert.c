/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:27:49 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/08 11:28:34 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_rb_ra(t_list **a, t_list **b, t_number candidate)
{
	int		i;

	i = ft_min(candidate.order, candidate.position);
	while (i-- && !ft_rotate(a, b))
		write(1, "rr\n", 3);
	if (candidate.order > candidate.position)
	{
		i = candidate.order - candidate.position;
		while (i-- && !ft_rotate(b, NULL))
			write(1, "rb\n", 3);
	}
	else
	{
		i = candidate.position - candidate.order;
		while (i-- && !ft_rotate(a, NULL))
			write(1, "ra\n", 3);
	}
	ft_push(b, a);
	write(1, "pa\n", 3);
}

static void		ft_rb_rra(t_list **a, t_list **b, t_number candidate)
{
	int		i;

	i = candidate.order;
	while (i-- && !ft_rotate(b, NULL))
		write(1, "rb\n", 3);
	i = ft_list_size(*a) - candidate.position;
	while (i-- && !ft_reverse_rotate(a, NULL))
		write(1, "rra\n", 4);
	ft_push(b, a);
	write(1, "pa\n", 3);
}

static void		ft_rrb_ra(t_list **a, t_list **b, t_number candidate)
{
	int i;

	i = ft_list_size(*b) - candidate.order;
	while (i-- && !ft_reverse_rotate(b, NULL))
		write(1, "rrb\n", 4);
	i = candidate.position;
	while (i-- && !ft_rotate(a, NULL))
		write(1, "ra\n", 3);
	ft_push(b, a);
	write(1, "pa\n", 3);
}

static void		ft_rrb_rra(t_list **a, t_list **b, t_number candidate)
{
	int		size_a;
	int		size_b;
	int		i;

	size_a = ft_list_size(*a);
	size_b = ft_list_size(*b);
	i = ft_min(size_b - candidate.order, size_a - candidate.position);
	while (i-- && !ft_reverse_rotate(a, b))
		write(1, "rrr\n", 4);
	if (size_b - candidate.order > size_a - candidate.position)
	{
		i = size_b - candidate.order
		- ft_min(candidate.order, size_a - candidate.position);
		while (i-- && !ft_reverse_rotate(b, NULL))
			write(1, "rrb\n", 4);
	}
	else
	{
		i = size_a - candidate.position
		- ft_min(size_b - candidate.order, size_a - candidate.position);
		while (i-- && !ft_reverse_rotate(a, NULL))
			write(1, "rra\n", 4);
	}
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void			ft_insert_candidate(t_list **a, t_list **b, t_number candidate)
{
	if (candidate.order * 2 < ft_list_size(*b))
	{
		if (candidate.position * 2 < ft_list_size(*a) + 1)
			ft_rb_ra(a, b, candidate);
		else
			ft_rb_rra(a, b, candidate);
	}
	else
	{
		if (candidate.position * 2 < ft_list_size(*a) + 1)
			ft_rrb_ra(a, b, candidate);
		else
			ft_rrb_rra(a, b, candidate);
	}
}
