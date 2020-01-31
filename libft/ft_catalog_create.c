/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:12:35 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/01/25 17:01:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_catalog	*ft_catalog_create(int fd, char *str)
{
	t_catalog	*current;

	current = malloc(sizeof(t_catalog));
	if (current)
	{
		current->fd = fd;
		current->str = str;
		current->next = NULL;
	}
	return (current);
}
