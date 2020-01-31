/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:14:20 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/09/09 11:47:53 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*buffer;

	if (!s)
		return (NULL);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	buffer = result;
	while (start > 0)
	{
		s++;
		start--;
	}
	while (len > 0)
	{
		*result = *s;
		result++;
		s++;
		len--;
	}
	*result = '\0';
	return (buffer);
}
