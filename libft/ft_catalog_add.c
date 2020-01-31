/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:16:11 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/01/25 17:01:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_catalog	*ft_catalog_add(t_catalog **begin_catalog, int fd, char *str)
{
	t_catalog	*current;

	if (!(*begin_catalog))
	{
		*begin_catalog = ft_catalog_create(fd, str);
		current = *begin_catalog;
	}
	else
	{
		current = *begin_catalog;
		while (current->next)
			current = current->next;
		current->next = ft_catalog_create(fd, str);
		current = current->next;
	}
	return (current);
}
