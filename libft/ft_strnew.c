/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:27:40 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/09/13 16:00:50 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	char	*buffer;

	if ((size + 1) < size)
		return (NULL);
	result = (char *)malloc(size + 1);
	if (!result)
		return (NULL);
	buffer = result;
	while (size > 0)
	{
		*result = '\0';
		result++;
		size--;
	}
	*result = '\0';
	return (buffer);
}
