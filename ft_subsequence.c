#include "push_swap.h"

static void			ft_fill_data(int *array, int *length, int *predecessor, int size)
{
	int		i;
	int		j;

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

static int			ft_find_max(int *length, int size, int *index)
{
	int		max;
	int		j;

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

static t_list		*ft_form_result(int	*array, int *predecessor, int i, int max)
{
	t_list	*result;
	int		*buffer;
	int		j;

	buffer = (int*)malloc(sizeof(int) * max);
	j = i;
	i = max - 1;
	while (j > -1)
	{
		buffer[i] = array[j];
		i--;
		if (j == predecessor[j])
			j = -1;
		else
			j = predecessor[j];
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

t_list			*ft_find_sequence(t_list **a)
{
	t_list	*result;
	int		*array;
	int		*length;
	int		*predecessor;
	int		i;

	array = (int*)malloc(sizeof(int) * ft_list_size(*a));
	length = (int*)malloc(sizeof(int) * ft_list_size(*a));
	predecessor = (int*)malloc(sizeof(int) * ft_list_size(*a));
	result = *a;
	i = 0;
	while (result)
	{
		array[i] = result->number;
		length[i] = 1;
		predecessor[i++] = -1;
		result = result->next;
	}
	ft_fill_data(array, length, predecessor, ft_list_size(*a));
	result = ft_form_result(array, predecessor, i,
		ft_find_max(length, ft_list_size(*a), &i));
	free(array);
	free(length);
	free(predecessor);
	return (result);
}
