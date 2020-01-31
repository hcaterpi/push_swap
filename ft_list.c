#include "push_swap.h"

t_list	*ft_list_create(int number)
{
	t_list	*current;

	current = malloc(sizeof(t_list));
	if (current)
	{
		current->number = number;
		current->next = NULL;
	}
	return (current);
}

t_list	*ft_list_add(t_list **head, int number)
{
	t_list	*current;

	if (!(*head))
	{
		*head = ft_list_create(number);
		current = *head;
	}
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = ft_list_create(number);
		current = current->next;
	}
	return (current);
}

int		ft_list_size(t_list *head)
{
	int size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

int		ft_list_find(t_list *head, int number)
{
	t_list	*current;

	current = head;
	while (current)
	{
		if (current->number == number)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_list_clear(t_list **head)
{
	t_list *current;

	while (head && *head)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
}