/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:35:33 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/12 18:43:04 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s, char c)
{
	int		result;
	int		flag;

	result = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			result++;
			flag = 1;
		}
		else if (*s == c && flag == 1)
			flag = 0;
		s++;
	}
	return (result);
}

static int		ft_length(char const *s, char c)
{
	int		result;

	result = 0;
	while (*s && *s != c)
	{
		result++;
		s++;
	}
	return (result);
}

static char		*ft_fill(char *dest, char const *s, char c)
{
	while (*s && *s != c)
	{
		*dest = *s;
		dest++;
		s++;
	}
	*dest = '\0';
	return ((char *)s);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = (char *)malloc(ft_length(s, c) + 1);
			if (!result[i] && ft_strclean(result))
				return (NULL);
			s = ft_fill(result[i], s, c);
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
