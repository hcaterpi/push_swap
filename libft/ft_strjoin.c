/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:32:48 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/09/09 12:07:42 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_length(const char *s)
{
	size_t i;

	i = 0;
	while (s && *s)
	{
		i++;
		s++;
	}
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char *result;
	char *buffer;

	result = (char *)malloc(ft_length(s1) + ft_length(s2) + 1);
	if (!result)
		return (NULL);
	buffer = result;
	while (s1 && *s1)
	{
		*result = *s1;
		result++;
		s1++;
	}
	while (s2 && *s2)
	{
		*result = *s2;
		result++;
		s2++;
	}
	*result = '\0';
	return (buffer);
}
