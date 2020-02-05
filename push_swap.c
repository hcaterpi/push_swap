#include "push_swap.h"

int	 	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	while (++i < argc)
	{
		if (ft_isinteger(argv[i]) && !ft_list_find(a, ft_atoi(argv[i])))
			ft_list_add(&a, ft_atoi(argv[i]));
		else
			return (ft_clean(&a, &b, 1));
	}
	ft_sort(&a, &b);
	return (ft_clean(&a, &b, 0));
}
