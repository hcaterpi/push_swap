/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:26:54 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/15 13:55:47 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_issorted(t_list **head)
{
	t_list	*buffer;

	buffer = *head;
	while (buffer && buffer->next)
	{
		if (buffer->number > buffer->next->number)
			return (0);
		buffer = buffer->next;
	}
	return (1);
}

int				ft_input(int ac, char **av, t_list **a)
{
	char	**input;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		input = ft_strsplit(av[i], ' ');
		j = 0;
		while (input[j] != NULL)
		{
			if (ft_isinteger(input[j]) && !ft_list_find(*a, ft_atoi(input[j])))
				ft_list_add(a, ft_atoi(input[j]));
			else if (ft_strclean(input))
				return (0);
			j++;
		}
		ft_strclean(input);
	}
	return (1);
}

int				ft_clean(t_list **a, t_list **b, int command)
{
	if (command == 1)
		write(2, "Error\n", 6);
	ft_list_clear(a);
	ft_list_clear(b);
	return (command);
}
