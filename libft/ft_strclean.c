/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:53:53 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/12 15:58:59 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strclean(char **str)
{
	int i;

	if (!str)
		return (1);
	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
	return (1);
}
