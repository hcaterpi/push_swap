#include "libft.h"

void	ft_putstr(char *s)
{
	char	*buffer;

	buffer = s;
	while (*buffer)
	{
		write(1, buffer, 1);
		buffer++;
	}
}
