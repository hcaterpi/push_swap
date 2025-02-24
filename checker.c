/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:16:29 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/15 14:00:15 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_clean_and_run(char *str, int result)
{
	free(str);
	return (result);
}

static int		ft_distributor(t_list **a, t_list **b, char *command)
{
	if (ft_strequ(command, "sa"))
		ft_swap(a, NULL);
	else if (ft_strequ(command, "sb"))
		ft_swap(b, NULL);
	else if (ft_strequ(command, "ss"))
		ft_swap(a, b);
	else if (ft_strequ(command, "pa"))
		ft_push(b, a);
	else if (ft_strequ(command, "pb"))
		ft_push(a, b);
	else if (ft_strequ(command, "ra"))
		ft_rotate(a, NULL);
	else if (ft_strequ(command, "rb"))
		ft_rotate(b, NULL);
	else if (ft_strequ(command, "rr"))
		ft_rotate(a, b);
	else if (ft_strequ(command, "rra"))
		ft_reverse_rotate(a, NULL);
	else if (ft_strequ(command, "rrb"))
		ft_reverse_rotate(b, NULL);
	else if (ft_strequ(command, "rrr"))
		ft_reverse_rotate(a, b);
	else
		return (ft_clean_and_run(command, 1));
	return (ft_clean_and_run(command, 0));
}

int				main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*buffer;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	if (!ft_input(argc, argv, &a))
		return (ft_clean(&a, &b, 1));
	while (ft_gnl(0, &buffer) > 0)
		if (ft_distributor(&a, &b, buffer))
			return (ft_clean(&a, &b, 1));
	if (ft_issorted(&a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_clean(&a, &b, 0));
}
