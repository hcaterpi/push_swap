/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:42:18 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/12 18:42:28 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char *base, const char *addition)
{
	char	*result;
	char	*buffer;
	char	*trash;

	result = malloc(ft_strlen(base) + ft_strlen(addition) + 1);
	buffer = result;
	trash = base;
	while (*base)
	{
		*buffer = *base;
		buffer++;
		base++;
	}
	free(trash);
	while (*addition)
	{
		*buffer = *addition;
		buffer++;
		addition++;
	}
	*buffer = '\0';
	return (result);
}
