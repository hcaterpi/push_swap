/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:30:23 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/12 16:17:59 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_list_copy(t_list **a)
{
	t_list	*result;
	t_list	*buffer;

	result = NULL;
	buffer = *a;
	while (buffer)
	{
		ft_list_add(&result, buffer->number);
		buffer = buffer->next;
	}
	return (result);
}

static int		ft_lines(char *str)
{
	int		result;
	char	*buffer;

	result = 0;
	buffer = str;
	while (*buffer)
	{
		if (*buffer == '\n')
			result++;
		buffer++;
	}
	return (result);
}

void			ft_sort(t_list **a, t_list **b)
{
	t_list		*replica;
	char		*base_result;
	char		*optimized_result;

	if (ft_issorted(a))
		return ;
	replica = ft_list_copy(a);
	base_result = ft_base_sort(&replica, b);
	ft_clean(&replica, NULL, 0);
	replica = ft_list_copy(a);
	optimized_result = ft_optimized_sort(&replica, b);
	ft_clean(&replica, NULL, 0);
	if (ft_lines(base_result) < ft_lines(optimized_result))
		ft_putstr(base_result);
	else
		ft_putstr(optimized_result);
	free(base_result);
	free(optimized_result);
	return ;
}
