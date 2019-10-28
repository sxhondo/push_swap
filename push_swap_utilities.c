#include "push_swap.h"

//void			sort_small_stack(t_list **a, t_list **b)
//{
//	int 		i;
//	int 		tmp;
//
//	i = 0;
//	while (!(is_sorted(a, 0)))
//	{
//		tmp = get_index_for_value(a, find_minmax(a, 0));
//		rot_index_on_top(a, tmp, 'a');
//		do_push(a, b, 'b');
//		ft_printf("pb\n");
//		i++;
//	}
//	while (i--)
//	{
//		tmp = get_index_for_value(b, find_minmax(b, 1));
//		rot_index_on_top(b, tmp, 'b');
//		do_push(a, b, 'a');
//		ft_printf("pa\n");
//	}
//}

//int				insertion_a(t_list **a, t_list **b)
//{
//	int 		i, k;
//	int 		llen = ft_lstlen(a);
//
//	k = llen;
//	while (llen--)
//	{
//		i = get_index_for_value(a, find_minmax(a, 1));
//		rot_index_on_top(a, i, 'a');
//		do_push(a, b, 'b');
//		ft_printf("pb\n");
//	}
//	return (k);
//}
//
//int				insertion_b(t_list **a, t_list **b)
//{
//	int 		i, k;
//	int 		llen = ft_lstlen(b);
//
//	k = llen;
//	while (llen--)
//	{
////		print_hor(a, b);
//		i = get_index_for_value(b, find_minmax(b, 0));
//		rot_index_on_top(b, i, 'b');
//		do_push(a, b, 'a');
//		do_rot(a);
//		ft_printf("pa\n");
//	}
//	return (k);
//}

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
		if (*((int *)tmp->content) < min)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int 			find_greater(t_list **stack, int val)
{
	t_list		*tmp;
	int 		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) > val)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
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

int 			find_less_greater(t_list **stack, int min, int max)
{
	t_list		*tmp;
	int 		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) < min && *((int *)tmp->content) > max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int					rot_index_on_top(t_list **stack, int index, char dst)
{
	int 		llen;

	llen = ft_lstlen(stack);
	if (index < 0)
		return (0);
	if (index <= llen / 2)
	{
		while (index-- > 0)
		{
			do_rot(stack);
			ft_printf("r%c\n", dst);
		}
	}
	else
	{
		while (index++ <= llen - 1)
		{
			do_rev_rot(stack);
			ft_printf("rr%c\n", dst);
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

void				sort_two(t_list **stack, char c)
{
	int 			a;
	int 			b;
	a = *((int *)(*stack)->content);
	b = *((int *)(*stack)->next->content);
	a > b ? do_swap(stack) : NULL;
	ft_printf("s%c\n", c);
}

void				small_sort(t_list **stack, int n, char dst)
{
	t_list *tmp;
	int a;
	int b;
	int c;

	while (!is_sorted(stack, 0))
	{
		a = *((int *) (*stack)->content);
		b = *((int *) (*stack)->next->content);
		c = *((int *) (*stack)->next->next->content);
		if (a > b && a > c && b < c) /* 3 1 2 */
		{
			do_rot(stack);
			ft_printf("r%c\n", dst);
		}
		if (a > b && a > c && b > c)
		{
			do_swap(stack);
			do_rev_rot(stack);
			ft_printf("s%c\nrr%c\n", dst, dst);
		}
		if (a > b && a < c && b < c)
		{
			do_swap(stack);
			ft_printf("s%c\n", dst);
		}
		if (a < b && a > c && b > c)
		{
			do_rev_rot(stack);
			ft_printf("rr%c\n", dst);
		}
		if (a < b && a < c && b > c)
		{
			do_swap(stack);
			do_rot(stack);
			ft_printf("s%c\nr%c\n", dst, dst);
		}
	}
}

int 			find_medvalue(t_list **stack, int llen)
{
	int 		j;
	int 		i;
	int 		res;
	t_list		*tmp;

	j = llen;
	res = 0;
	tmp = *stack;
	while (tmp && j--)
	{
		res += *((int *)tmp->content);
		tmp = tmp->next;
	}
	if (llen == 0)
		return (-1);
	res /= llen;
	i = 0;
	while (res)
	{
		j = llen;
		res += i;
		tmp = *stack;
		while (tmp && j--)
		{
			if (res == *((int *)tmp->content))
				return (res);
			tmp = tmp->next;
		}
		j = llen;
		res -= i;
		tmp = *stack;
		while (tmp && j--)
		{
			if (res == *((int *)tmp->content))
				return (res);
			tmp = tmp->next;
		}
		i++;
	}
	return (-1);
}


void			smart_rot(t_list **a, t_list **b,
						  int min_a_i, int min_b_i)
{

	int 		len_a = ft_lstlen(a);
	int 		len_b = ft_lstlen(b);
	int 		medi_a = len_a / 2; //50
	int 		medi_b = len_b / 2; //50

	if (min_a_i <= medi_a && min_b_i <= medi_b)
	{
		while (min_a_i > 0 && min_b_i > 0)
		{
			min_a_i--;
			min_b_i--;
			do_rot(a);
			do_rot(b);
			ft_printf("rr\n");
		}
	}
	if (min_a_i > medi_a && min_b_i > medi_b)
	{
		while (min_a_i < len_a && min_b_i < len_a)
		{
			min_a_i++;
			min_b_i++;
			do_rev_rot(a);
			do_rev_rot(b);
			ft_printf("rrr\n");
		}
	}
	if (min_a_i > 0 && min_a_i <= medi_a)
		while (min_a_i > 0)
		{do_rot(a), ft_printf("ra\n"); min_a_i--;}
	else if (min_a_i > medi_a)
		while (min_a_i < len_b)
		{do_rev_rot(a), ft_printf("rra\n"); min_a_i++;}
	if (min_b_i > 0 && min_b_i <= medi_b)
		while (min_b_i > 0)
		{do_rot(b), ft_printf("rb\n"); min_b_i--;}
	else if (min_b_i > medi_b)
		while (min_b_i < len_b)
		{do_rev_rot(b), ft_printf("rrb\n"); min_b_i++;}


}