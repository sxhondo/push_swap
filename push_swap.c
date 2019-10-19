#include "push_swap.h"

int 				ops;

/*
int 			check_max(t_list **stack, int k_val)
{
	t_list		*tmp;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) > k_val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
int				find_min_max(t_list **stack, int mix)
{
	t_list		*i;
	t_list		*j;
	int 		curr;
	int 		t;
	i = *stack;
	while (i)
	{
		t = 0;
		j = *stack;
		curr = *((int *)i->content);
		while (j)
		{
			if (!mix && curr <= *((int *)j->content))
				t++;
			if (mix && curr >= *((int *)j->content))
				t++;
			j = j->next;
		}
		if (t == ft_lstlen(stack))
			return (curr);
		i = i->next;
	}
	return (-1);
}
*/

int				brute_force(t_list **a, t_list **b)
{
	int 		top_a;
	int 		top_b;
	unsigned 	i, j;

	if (!*a)
		return (1);
	top_a = *a ? *((int *)(*a)->content) : 0;
	top_b = *b ? *((int *)(*b)->content) : 0;
	if (top_a > top_b)
	{do_push(a, b, 'b'); ft_printf("pb\n"); ops++;}
	else
	{
		i = 0;
		while (top_a < top_b)
		{
			do_push(a, b, 'a'); ft_printf("pa\n"); ops++;
			if ((*b))
				top_b = *((int *)(*b)->content);
			else
				top_b = 0;
			i++;
		}
		j = i;
		while (i--)
			do_rot(a);
		do_push(a, b, 'b'); ft_printf("pb\n"); ops++;
		while (i++ < j)
		{do_rev_rot(a); ft_printf("rra\n");} ops++;
	}
//	print_stacks(a, b);
	brute_force(a, b);
	return (1);
}

int 			find_medvalue(t_list **stack, int llen)
{
	int 		i;
	int 		res;
	t_list		*tmp;

	res = 0;
	tmp = *stack;
	while (tmp)
	{
		res += *((int *)tmp->content);
		tmp = tmp->next;
	}

	res /= llen;
	i = 0;
	while (res)
	{
		res += i;
		tmp = *stack;
		while (tmp)
		{
			if (res == *((int *)tmp->content))
				return (res);
			tmp = tmp->next;
		}
		res -= i;
		tmp = *stack;
		while (tmp)
		{
			if (res == *((int *)tmp->content))
				return (res);
			tmp = tmp->next;
		}
		i++;
	}
	return (-1);
}

int 			get_value_for_index(t_list **stack, int index)
{
	t_list		*tmp;

	tmp = *stack;
	while (index)
	{
		tmp = tmp->next;
		index--;
	}
	return (*((int *)tmp->content));
}

int 			get_index_for_value(t_list **stack, int value)
{
	int 		i;
	t_list		*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) == value)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int 			find_less(t_list **stack, int min)
{
	t_list		*tmp;
	int 		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) <= min)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int 			find_greater(t_list **stack, int min)
{
	t_list		*tmp;
	int 		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) >= min)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int					rot_to_top(t_list **stack, int k_val, char st)
{
	int 		llen;
	int 		value_i;

	llen = ft_lstlen(stack);
	value_i = find_less(stack, k_val);
	if (value_i < 0)
		return (0);
	if (value_i <= llen / 2)
	{
		while (value_i-- > 0)
		{
			do_rot(stack);
			ft_printf("r%c\n", st);
			ops++;
		}
	}
	else
	{
		while (value_i++ <= llen - 1)
		{
			do_rev_rot(stack);
			ft_printf("rr%c\n", st);
			ops++;
		}
	}
	return (1);
}

int					rot_value_to_top(t_list **stack, int value, char st)
{
	int 		llen;
	int 		value_i;

	llen = ft_lstlen(stack);
	value_i = get_index_for_value(stack, value);
	if (value_i < 0)
		return (0);
	if (value_i <= llen / 2)
	{
		while (value_i-- > 0)
		{
			do_rot(stack);
			ft_printf("r%c\n", st);
			ops++;
		}
	}
	else
	{
		while (value_i++ <= llen - 1)
		{
			do_rev_rot(stack);
			ft_printf("rr%c\n", st);
			ops++;
		}
	}
	return (1);
}


int 			is_sorted(t_list **stack, int mode) /* 0 - sorted, 1 - back sorted */
{
	t_list		*tmp;

	tmp = *stack;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if (!mode && *((int *)tmp->content) < *((int *)tmp->next->content))
			tmp = tmp->next;
		else if (mode && *((int *)tmp->content) > *((int *)tmp->next->content))
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int 			find_minmax(t_list **stack, int mode)
{
	t_list		*i;
	t_list		*j;
	int 		curr;

	i = *stack;
	while (i)
	{
		curr = *((int *)i->content);
		j = *stack;
		while (!mode && j && *((int *)j->content) >= curr)
			j = j->next;
		while (mode && j && *((int *)j->content) <= curr)
			j = j->next;
		if (!j)
			return (curr);
		i = i->next;
	}
	return (-1);
}

int				partition(t_list **a, t_list **b,
							 int m_index, char stack)
{
	int 		k_val;
	int 		i;

	if (stack == 'a' && (*a) && is_sorted(a, 0))
		return (0);
	if (stack == 'b' && (*b) && is_sorted(b, 1))
		return (0);
	i = 0;
	k_val = get_value_for_index(stack == 'a' ? a : b, m_index);
	while ((rot_to_top(stack == 'a' ? a : b, k_val, stack)) > 0)
	{
		do_push(a, b, stack == 'a' ? 'b' : 'a');
//		print_stacks(a, b);
		ft_printf("p%c\n", stack == 'a' ? 'b' : 'a');
		ops++;
		i++;
	}
//	print_stacks(a, b);
	return (i);
}

void				quick_sort(t_list **a, t_list **b,
							   int n, char stack)
{
  	if (is_sorted(stack == 'a' ? a : b, stack == 'a' ? 0 : 1)
		|| n == 0 || n == 1)
		return;

	int top_half_len = 0;
	int tmp = 0;
	int m_index = n - 1;

//	print_stacks(a, b);
	top_half_len = partition(a, b, m_index, stack);
	if (ft_lstlen(a) == 2)
		*((int *)(*a)->content) > *((int *)(*a)->next->content) ? do_swap(a) : NULL;
//	print_stacks(a, b);

	tmp = top_half_len;
	while (tmp--)
	{
		rot_value_to_top(b, find_minmax(b, 1), 'b');
//		print_stacks(a, b);
		do_push(a, b, 'a');
		ft_printf("pa\n");
		ops++;
	}
	tmp = top_half_len - 1 ? top_half_len - 1 : ft_lstlen(a);
//	print_stacks(a, b);
	quick_sort(a, b, tmp, stack);
	quick_sort(a, b, n - top_half_len, stack);
}

void 			sort_stacks(int *nums, unsigned arg_am)
{
	t_list		*a;
	t_list		*b;

	ops = 0;
	b = NULL;
	a = fill_a(nums, arg_am);

//	brute_force(&a, &b);

	int med_value = find_medvalue(&a, ft_lstlen(&a));
	int med_i = get_index_for_value(&a, med_value);

	partition(&a, &b, med_i, 'a');
//	print_stacks(&a, &b);
	rot_value_to_top(&a, find_minmax(&a, 1), 'a');
	do_rot(&a);
	ft_printf("ra\n");
//	print_stacks(&a, &b);
	quick_sort(&a, &b, ft_lstlen(&a), 'a');
	print_stacks(&a, &b);


//	med_value = find_medvalue(&b, ft_lstlen(&b));
//	med_i = get_index_for_value(&b, med_value);
//
//	quick_sort(&a, &b, ft_lstlen(&b), 'b');
//	print_stacks(&a, &b);

	while (rot_value_to_top(&b, find_minmax(&b, 1), 'b'))
	{
		do_push(&a, &b, 'a');
		ft_printf("pa\n");
		ops++;
	}
//	print_stacks(&a, &b);
//	ft_printf("\n[%d]\n", ops);
	free_stacks(&a, &b);
}

