/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:40:45 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/15 14:51:14 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_sort_triplet(t_list **stack, char **result)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	second = first->next;
	if (!second->next && first->number > second->number)
	{
		ft_swap(stack, NULL);
		*result = ft_stradd(*result, "sa\n");
		return ;
	}
	third = second->next;
	if (((first->number > second->number)
	&& ((first->number > third->number && second->number > third->number)
	|| (first->number < third->number && second->number < third->number)))
	|| (first->number < second->number && first->number < third->number
	&& second->number > third->number))
	{
		ft_swap(stack, NULL);
		*result = ft_stradd(*result, "sa\n");
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
	result = 0;
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

static void		ft_normalize(t_list **a, char **result)
{
	int		head;
	int		size;

	head = ft_find_head(a);
	size = ft_list_size(*a);
	if (head * 2 < size)
	{
		while (head > 0 && head-- && !ft_rotate(a, NULL))
			*result = ft_stradd(*result, "ra\n");
	}
	else
	{
		head = size - head;
		while (head-- && !ft_reverse_rotate(a, NULL))
			*result = ft_stradd(*result, "rra\n");
	}
}

char			*ft_base_sort(t_list **a, t_list **b)
{
	char		*result;
	t_number	candidate;
	int			size;

	if ((result = (char*)malloc(sizeof(char))))
		*result = '\0';
	size = ft_list_size(*a);
	while (size > 3)
	{
		ft_push(a, b);
		result = ft_stradd(result, "pb\n");
		size--;
	}
	ft_sort_triplet(a, &result);
	while (*b)
	{
		candidate = ft_find_candidate(a, b);
		ft_insert_candidate(a, b, candidate, &result);
	}
	ft_normalize(a, &result);
	return (result);
}

char			*ft_optimized_sort(t_list **a, t_list **b)
{
	char		*result;
	t_list		*subsequence;
	t_list		*trash;
	int			size;

	result = ft_strnew(0);
	size = ft_list_size(*a);
	subsequence = ft_find_sequence(a);
	trash = subsequence;
	while (size-- > 0)
	{
		if (subsequence && (*a)->number == subsequence->number)
		{
			ft_rotate(a, b);
			result = ft_stradd(result, "rr\n");
			subsequence = subsequence->next;
		}
		else if (!ft_push(a, b))
			result = ft_stradd(result, "pb\n");
	}
	ft_list_clear(&trash);
	while (*b)
		ft_insert_candidate(a, b, ft_find_candidate(a, b), &result);
	ft_normalize(a, &result);
	return (result);
}
