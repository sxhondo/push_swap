//#include "push_swap.h"
//
//int 				ops;
//
//int 			find_medvalue(t_list **stack, int llen)
//{
//	int 		i;
//	int 		res;
//	t_list		*tmp;
//
//	res = 0;
//	tmp = *stack;
//	while (tmp)
//	{
//		res += *((int *)tmp->content);
//		tmp = tmp->next;
//	}
//
//	res /= llen;
//	i = 0;
//	while (res)
//	{
//		res += i;
//		tmp = *stack;
//		while (tmp)
//		{
//			if (res == *((int *)tmp->content))
//				return (res);
//			tmp = tmp->next;
//		}
//		res -= i;
//		tmp = *stack;
//		while (tmp)
//		{
//			if (res == *((int *)tmp->content))
//				return (res);
//			tmp = tmp->next;
//		}
//		i++;
//	}
//	return (-1);
//}
//
//int 			get_value_for_index(t_list **stack, int index)
//{
//	t_list		*tmp;
//
//	tmp = *stack;
//	while (index)
//	{
//		tmp = tmp->next;
//		index--;
//	}
//	return (*((int *)tmp->content));
//}
//
//int 			get_index_for_value(t_list **stack, int value)
//{
//	int 		i;
//	t_list		*tmp;
//
//	i = 0;
//	tmp = *stack;
//	while (tmp)
//	{
//		if (*((int *)tmp->content) == value)
//			return (i);
//		i++;
//		tmp = tmp->next;
//	}
//	return (-1);
//}
//
//int 			find_less(t_list **stack, int min)
//{
//	t_list		*tmp;
//	int 		i;
//
//	i = 0;
//	tmp = *stack;
//	while (tmp)
//	{
//		if (*((int *)tmp->content) < min)
//			return (i);
//		i++;
//		tmp = tmp->next;
//	}
//	return (-1);
//}
//
//int 			find_greater(t_list **stack, int min)
//{
//	t_list		*tmp;
//	int 		i;
//
//	i = 0;
//	tmp = *stack;
//	while (tmp)
//	{
//		if (*((int *)tmp->content) > min)
//			return (i);
//		i++;
//		tmp = tmp->next;
//	}
//	return (-1);
//}
//
//
//int 			is_sorted(t_list **stack, int mode) /* 0 - sorted, 1 - back sorted */
//{
//	t_list		*tmp;
//
//	tmp = *stack;
//	if (!tmp)
//		return (1);
//	while (tmp->next)
//	{
//		if (!mode && *((int *)tmp->content) < *((int *)tmp->next->content))
//			tmp = tmp->next;
//		else if (mode && *((int *)tmp->content) > *((int *)tmp->next->content))
//			tmp = tmp->next;
//		else
//			return (0);
//	}
//	return (1);
//}
//
//int 			find_minmax(t_list **stack, int mode)
//{
//	t_list		*i;
//	t_list		*j;
//	int 		curr;
//
//	i = *stack;
//	while (i)
//	{
//		curr = *((int *)i->content);
//		j = *stack;
//		while (!mode && j && *((int *)j->content) >= curr)
//			j = j->next;
//		while (mode && j && *((int *)j->content) <= curr)
//			j = j->next;
//		if (!j)
//			return (curr);
//		i = i->next;
//	}
//	return (-1);
//}
//
//int					rot_index_on_top(t_list **stack, int index, char dst)
//{
//	int 		llen;
//
//	llen = ft_lstlen(stack);
//	if (index < 0)
//		return (0);
//	if (index <= llen / 2)
//	{
//		while (index-- > 0)
//		{
//			do_rot(stack);
//			ft_printf("r%c\n", dst);
//		}
//	}
//	else
//	{
//		while (index++ <= llen - 1)
//		{
//			do_rev_rot(stack);
//			ft_printf("rr%c\n", dst);
//		}
//	}
//	return (1);
//}
//
//void			smart_rot(t_list **a, t_list **b,
//			int min_a_i, int min_b_i)
//{
//
//	int 		len_a = ft_lstlen(a);
//	int 		len_b = ft_lstlen(b);
//	int 		medi_a = len_a / 2; //50
//	int 		medi_b = len_b / 2; //50
//
//	if (min_a_i <= medi_a && min_b_i <= medi_b)
//	{
//		while (min_a_i > 0 && min_b_i > 0)
//		{
//			min_a_i--;
//			min_b_i--;
//			do_rot(a);
//			do_rot(b);
//			ft_printf("rr\n");
//			ops++;
//		}
//	}
//	if (min_a_i > medi_a && min_b_i > medi_b)
//	{
//		while (min_a_i < len_a && min_b_i < len_a)
//		{
//			min_a_i++;
//			min_b_i++;
//			do_rev_rot(a);
//			do_rev_rot(b);
//			ft_printf("rrr\n");
//			ops++;
//		}
//	}
//	if (min_a_i > 0 && min_a_i <= medi_a)
//		while (min_a_i > 0)
//			{do_rot(a), ft_printf("ra\n"); min_a_i--; ops++; }
//	else if (min_a_i > medi_a)
//		while (min_a_i < len_b)
//			{do_rev_rot(a), ft_printf("rra\n"); min_a_i++; ops++; }
//	if (min_b_i > 0 && min_b_i <= medi_b)
//		while (min_b_i > 0)
//			{do_rot(b), ft_printf("rb\n"); min_b_i--; ops++; }
//	else if (min_b_i > medi_b)
//		while (min_b_i < len_b)
//			{do_rev_rot(b), ft_printf("rrb\n"); min_b_i++; ops++; }
//
//
//}
//
//void				small_sort(t_list **stack, int n, char dst)
//{
//	t_list *tmp;
//	int a;
//	int b;
//	int c;
//
//	if (n == 3)
//	{
//		if (dst == 'a')
//			while (!is_sorted(stack, 0))
//			{
//				a = *((int *) (*stack)->content);
//				b = *((int *) (*stack)->next->content);
//				c = *((int *) (*stack)->next->next->content);
//				if (a > b && a > c && b < c) /* 3 1 2 */
//				{
//					do_rot(stack);
//					ft_printf("r%c\n", dst);
//				}
//				if (a > b && a > c && b > c)
//				{
//					do_swap(stack);
//					do_rev_rot(stack);
//					ft_printf("s%c\nrr%c\n", dst, dst);
//				}
//				if (a > b && a < c && b < c)
//				{
//					do_swap(stack);
//					ft_printf("s%c\n", dst);
//				}
//				if (a < b && a > c && b > c)
//				{
//					do_rev_rot(stack);
//					ft_printf("rr%c\n", dst);
//				}
//				if (a < b && a < c && b > c)
//				{
//					do_swap(stack);
//					do_rot(stack);
//					ft_printf("s%c\nr%c\n", dst, dst);
//				}
//			}
//		if (dst == 'b')
//			while (!is_sorted(stack, 1))
//			{
//				a = *((int *) (*stack)->content);
//				b = *((int *) (*stack)->next->content);
//				c = *((int *) (*stack)->next->next->content);
//
//				if (a < b && a < c && b > c)
//				{
//					do_rot(stack);
//					ft_printf("r%c\n", dst);
//				}
//				if (a < b && a < c && b < c)
//				{
//					do_rot(stack);
//					do_swap(stack);
//					ft_printf("r%c\ns%c\n", dst, dst);
//				}
//				if (a > b && a < c && b < c)
//				{
//					do_rev_rot(stack);
//					ft_printf("rr%c\n", dst);
//				}
//				if (a < b && a > c && b > c)
//				{
//					do_swap(stack);
//					ft_printf("s%c\n", dst);
//				}
//				if (a > b && a > c && b < c)
//				{
//					do_rev_rot(stack);
//					do_swap(stack);
//					ft_printf("rr%c\ns%c\n", dst, dst);
//				}
//			}
//	}
////	print_stacks(stack, NULL);
//
//	if (n == 2)
//	{
//		a = *((int *)(*stack)->content);
//		b = *((int *)(*stack)->next->content);
//		a > b ? do_swap(stack) : NULL;
//		ft_printf("s%c\n", dst);
//	}
//}
//
//int				quick_sort(t_list **a, t_list **b,
//							   int n, char stack)
//{
//	int k_val;
//	int tmp;
//	int i_a, i_b;
//
//	print_hor(a, b);
//	if (n <= 3)
//	{
//		if (n == 3 || n == 2)
//			small_sort(stack == 'a' ? a : b, n, stack);
//		return (0);
//	}
//	if ((stack == 'a' && is_sorted(a, 0))
//		|| (stack == 'b' && is_sorted(b, 1)))
//		return (0);
//	k_val = stack == 'a' ? find_medvalue(a, ft_lstlen(a)) : find_minmax(b, 1);
//	tmp = ft_lstlen(a) > ft_lstlen(b) ? ft_lstlen(a) : ft_lstlen(b);
//	while (tmp--)
//	{
//		i_a = find_less(a, k_val);
//		i_b = find_greater(b, k_val);
//		if (i_a == -1 && i_b == -1)
//			break;
//		smart_rot(a, b, i_a, i_b);
//		if (i_a > -1)
//		{
//			do_push(a, b, 'b');
//			do_rot(b);
//			ft_printf("pb\nrb\n");
//		}
//		if (i_b > -1)
//		{
//			do_push(a, b, 'a');
//			ft_printf("pa\n");
//		}
//	}
//	tmp = get_index_for_value(stack == 'a' ? a : b, k_val);
//	rot_index_on_top(stack == 'a' ? a : b, tmp, stack);
//	do_push(a, b, stack == 'a' ? 'b' : 'a');
//	print_hor(a, b);
//	quick_sort(a, b, ft_lstlen(a), 'a');
//	quick_sort(a, b, ft_lstlen(b), 'b');
//	return (-1);
//
//}
//void 			sort_stacks(int *nums, unsigned arg_am)
//{
//	t_list		*a;
//	t_list		*b;
//	int 		tmp;
//
//	ops = 0;
//	b = NULL;
//	a = fill_a(nums, arg_am);
//
//	if ((tmp = ft_lstlen(&a)) > 6)
//	{
//		tmp /= 2;
//		while (tmp--)
//		{
//			do_push(&a, &b, 'b');
//			ft_printf("pb\n");
//		}
//	}
//	else
//	{
//		while (!(is_sorted(&a, 0)))
//		{
//			tmp = get_index_for_value(&a, find_minmax(&a, 0));
//			rot_index_on_top(&a, tmp, 'a');
//			do_push(&a, &b, 'b');
//			ft_printf("pb\n");
//		}
//	}
//	quick_sort(&a, &b, ft_lstlen(&a), 'a');
//	tmp = ft_lstlen(&b);
//	if (b)
//		while (tmp--)
//		{
//			do_push(&a, &b, 'a');
//			ft_printf("pa\n");
//		}
//	print_hor(&a, &b);
//}
//
