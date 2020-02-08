/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:21:43 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/08 11:22:04 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinteger(const char *str)
{
	char	*buffer;
	int		length;

	buffer = (char *)str;
	if (*buffer == '-' || *buffer == '+')
		buffer++;
	if ((length = ft_strlen(buffer)) > 10 || length == 0)
		return (0);
	while (*buffer)
	{
		if (*buffer < '0' || *buffer > '9')
			return (0);
		buffer++;
	}
	buffer = (char *)str;
	if (((*buffer == '-' && ft_strcmp(buffer, "-2147483648") > 0)
	|| (*buffer == '+' && ft_strcmp(buffer, "+2147483647") > 0)
	|| (ft_strcmp(buffer, "2147483647") > 0)) && length == 10)
		return (0);
	return (1);
}
