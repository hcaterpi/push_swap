#include "libft.h"

t_catalog	*ft_catalog_find(t_catalog *begin_catalog, int fd)
{
	t_catalog	*current;

	current = begin_catalog;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	return (NULL);
}
