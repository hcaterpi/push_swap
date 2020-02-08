/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catalog_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:24:40 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/08 11:24:41 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_catalog	*ft_catalog_find(t_catalog *begin_catalog, int fd)
{
	t_catalog	*current;

	current = begin_catalog;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	return (NULL);
}
