#include "push_swap.h"

static int 		arithmetic_mean(t_list **stack, int llen)
{
	int64_t 	res;
	t_list		*p;

	res = 0;
	p = *stack;
	while (p)
	{
		res += *((int *)p->content);
		p = p->next;
	}
	res /= llen;
	if (res >= INT32_MAX)
		put_error(3, stack);
	return ((int)res);
}

static int 		find_match(t_list **stack, int value)
{
	t_list		*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int 			find_medvalue(t_list **stack)
{
	int 		res;
	int 		llen;
	int 		i;

	llen = ft_lstlen(stack);
	res = arithmetic_mean(stack, llen);
	i = 0;
	while (res)
	{
		res += i;
		if ((find_match(stack, res)))
			return (res);
		res -= i;
		if ((find_match(stack, res)))
			return (res);
		i++;
	}
	return (-1);
}

