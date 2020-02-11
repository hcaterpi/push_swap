/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catalog_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:16:11 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/10 16:56:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_catalog_delete(t_catalog **begin_catalog, int fd)
{
	t_catalog	*current;
	t_catalog	*previous;

	current = *begin_catalog;
	previous = current;
	while (current)
	{
		if (current->fd == fd)
		{
			if (previous == current)
				*begin_catalog = current->next;
			else
				previous->next = current->next;
			if (current->str)
				free(current->str);
			free(current);
			return (0);
		}
		previous = current;
		current = current->next;
	}
	return (1);
}
