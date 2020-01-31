/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:10:04 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/09/08 17:34:26 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*buffer;
	char	*result;

	length = 0;
	buffer = (char *)s1;
	while (*s1)
	{
		length++;
		s1++;
	}
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	s1 = buffer;
	buffer = result;
	while (*s1)
	{
		*result = *s1;
		result++;
		s1++;
	}
	*result = '\0';
	return (buffer);
}
