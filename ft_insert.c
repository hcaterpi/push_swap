/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:27:49 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/10 13:51:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_rb_ra(t_list **a, t_list **b, t_number candidate, char **result)
{
	int		i;

	i = ft_min(candidate.order, candidate.position);
	while (i-- && !ft_rotate(a, b))
		*result = ft_stradd(*result, "rr\n");
	if (candidate.order > candidate.position)
	{
		i = candidate.order - candidate.position;
		while (i-- && !ft_rotate(b, NULL))
			*result = ft_stradd(*result, "rb\n");
	}
	else
	{
		i = candidate.position - candidate.order;
		while (i-- && !ft_rotate(a, NULL))
			*result = ft_stradd(*result, "ra\n");
	}
	ft_push(b, a);
	*result = ft_stradd(*result, "pa\n");
}

static void		ft_rb_rra(t_list **a, t_list **b, t_number candidate, char **result)
{
	int		i;

	i = candidate.order;
	while (i-- && !ft_rotate(b, NULL))
		*result = ft_stradd(*result, "rb\n");
	i = ft_list_size(*a) - candidate.position;
	while (i-- && !ft_reverse_rotate(a, NULL))
		*result = ft_stradd(*result, "rra\n");
	ft_push(b, a);
	*result = ft_stradd(*result, "pa\n");
}

static void		ft_rrb_ra(t_list **a, t_list **b, t_number candidate, char **result)
{
	int i;

	i = ft_list_size(*b) - candidate.order;
	while (i-- && !ft_reverse_rotate(b, NULL))
		*result = ft_stradd(*result, "rrb\n");
	i = candidate.position;
	while (i-- && !ft_rotate(a, NULL))
		*result = ft_stradd(*result, "ra\n");
	ft_push(b, a);
	*result = ft_stradd(*result, "pa\n");
}

static void		ft_rrb_rra(t_list **a, t_list **b, t_number candidate, char **result)
{
	int		size_a;
	int		size_b;
	int		i;

	size_a = ft_list_size(*a);
	size_b = ft_list_size(*b);
	i = ft_min(size_b - candidate.order, size_a - candidate.position);
	while (i-- && !ft_reverse_rotate(a, b))
		*result = ft_stradd(*result, "rrr\n");
	if (size_b - candidate.order > size_a - candidate.position)
	{
		i = size_b - candidate.order
		- ft_min(candidate.order, size_a - candidate.position);
		while (i-- && !ft_reverse_rotate(b, NULL))
			*result = ft_stradd(*result, "rrb\n");
	}
	else
	{
		i = size_a - candidate.position
		- ft_min(size_b - candidate.order, size_a - candidate.position);
		while (i-- && !ft_reverse_rotate(a, NULL))
			*result = ft_stradd(*result, "rra\n");
	}
	ft_push(b, a);
	*result = ft_stradd(*result, "pa\n");
}

void			ft_insert_candidate(t_list **a, t_list **b, t_number candidate, char **result)
{
	if (candidate.order * 2 < ft_list_size(*b))
	{
		if (candidate.position * 2 < ft_list_size(*a) + 1)
			ft_rb_ra(a, b, candidate, result);
		else
			ft_rb_rra(a, b, candidate, result);
	}
	else
	{
		if (candidate.position * 2 < ft_list_size(*a) + 1)
			ft_rrb_ra(a, b, candidate, result);
		else
			ft_rrb_rra(a, b, candidate, result);
	}
}
