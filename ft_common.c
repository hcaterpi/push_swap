/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:26:54 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/08 11:27:08 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_issorted(t_list **head)
{
	t_list	*buffer;

	buffer = *head;
	while (buffer && buffer->next)
	{
		if (buffer->number > buffer->next->number)
			return (0);
		buffer = buffer->next;
	}
	return (1);
}

int		ft_clean(t_list **a, t_list **b, int command)
{
	if (command == 1)
		write(2, "Error\n", 6);
	ft_list_clear(a);
	ft_list_clear(b);
	return (command);
}
