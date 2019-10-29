#include "push_swap.h"

t_list					*fill_a(int *nums, unsigned arg_am)
{
	int 				i;
	t_list				*node;
	t_list				*res;

	i = 0;
	res = NULL;
	while (i < arg_am)
	{
		if (!(node = ft_lstnew(&nums[i], sizeof(int))))
			return (NULL);
		ft_lstpushback(&res, node);
		i++;
	}
	return (res);
}