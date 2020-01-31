#include "libft.h"

static int	calculation(const char *str, char sign)
{
	long int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if ((result * 10 + *str - '0' < result) && sign == '+')
			return (-1);
		else if ((result * 10 + *str - '0' < result) && sign == '-')
			return (0);
		result = result * 10 + *str - '0';
		str++;
	}
	return (result);
}

int			ft_atoi(const char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			return (calculation(str, '+'));
		else if (*str == '+')
			return (calculation(++str, '+'));
		else if (*str == '-')
			return (calculation(++str, '-') * -1);
		else if (*str == ' ' || *str == '\t' || *str == '\n'
				|| *str == '\f' || *str == '\r' || *str == '\v')
			str++;
		else
			return (0);
	}
	return (0);
}
