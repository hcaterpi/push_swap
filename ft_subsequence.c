/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsequence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:35:25 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/12 18:38:04 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_fill_data(int *array, int *length,
				int *predecessor, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[j] > array[i])
			{
				if (length[j] + 1 > length[i])
				{
					length[j] = length[i] + 1;
					predecessor[j] = i;
				}
			}
			j++;
		}
		i++;
	}
}

static int		ft_find_max(int *length, int size, int *index)
{
	int max;
	int j;

	*index = 0;
	j = 0;
	max = 0;
	while (j < size)
	{
		if (length[j] > max)
		{
			*index = j;
			max = length[j];
		}
		j++;
	}
	return (max);
}

static t_list	*ft_form_result(int *array, int *predecessor, int max, int i)
{
	t_list	*result;
	int		*buffer;
	int		j;

	if (!(buffer = (int *)malloc(sizeof(int) * max)))
		return (NULL);
	j = i;
	i = max - 1;
	while (j > -1)
	{
		buffer[i] = array[j];
		i--;
		j = (j == predecessor[j]) ? -1 : predecessor[j];
	}
	result = NULL;
	i = 0;
	while (i < max)
	{
		ft_list_add(&result, buffer[i]);
		i++;
	}
	free(buffer);
	return (result);
}

int				ft_malloc_memory(int **arr, int **len, int **pre, t_list **a)
{
	t_list	*buffer;
	int		i;

	if (!(*arr = (int *)malloc(sizeof(int) * ft_list_size(*a))))
		return (0);
	if (!(*len = (int *)malloc(sizeof(int) * ft_list_size(*a))))
	{
		free(*arr);
		return (0);
	}
	if (!(*pre = (int *)malloc(sizeof(int) * ft_list_size(*a))))
	{
		free(*arr);
		free(*len);
		return (0);
	}
	buffer = *a;
	i = 0;
	while (buffer && ((*len)[i] = 1))
	{
		(*arr)[i] = buffer->number;
		(*pre)[i++] = -1;
		buffer = buffer->next;
	}
	return (1);
}

t_list			*ft_find_sequence(t_list **a)
{
	t_list	*result;
	int		*array;
	int		*length;
	int		*predecessor;
	int		i;

	array = NULL;
	length = NULL;
	predecessor = NULL;
	if (!ft_malloc_memory(&array, &length, &predecessor, a))
		return (NULL);
	i = 0;
	ft_fill_data(array, length, predecessor, ft_list_size(*a));
	result = ft_form_result(array, predecessor,
							ft_find_max(length, ft_list_size(*a), &i), i);
	free(array);
	free(length);
	free(predecessor);
	return (result);
}
