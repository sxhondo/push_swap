/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:50:48 by sxhondo           #+#    #+#             */
/*   Updated: 2019/10/01 13:50:49 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int				brute_force(t_list **a, t_list **b)
{
	int 		top_a;
	int 		top_b;
	unsigned 	i, j;
	unsigned 	ops;

	ops = 0;
	if (!*a)
		return (1);
	top_a = *a ? *((int *)(*a)->content) : 0;
	top_b = *b ? *((int *)(*b)->content) : 0;
	if (top_a > top_b && ++ops)
		do_push(a, b, 'b');
	else
	{
		i = 0;
		while (top_a < top_b)
		{
			do_push(a, b, 'a');
			ops++;
			if ((*b))
				top_b = *((int *)(*b)->content);
			else
				top_b = 0;
			i++;
		}
		j = i;
		while (i-- && ++ops)
			do_rot(a);
		do_push(a, b, 'b');
		ops++;
		while (i++ < j && ++ops)
			do_rev_rot(a);
	}
	print_stacks(a, b);
	brute_force(a, b);
	return (1);
}
*/

int 			is_sorted(t_list **stack)
{
	t_list		*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (*((int *)tmp->content) < *((int *)tmp->next->content))
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int 			is_back_sorted(t_list **stack)
{
	t_list		*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (*((int *)tmp->content) > *((int *)tmp->next->content))
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}


int 			find_index(t_list **stack, int min)
{
	t_list		*tmp;
	int 		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) == min)
			return (i);
		i++;
		tmp = tmp->next;
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

void			value_to_top(t_list **stack, int value)
{
	int 		llen;
	int 		value_i;

	llen = ft_lstlen(stack);
	value_i = find_index(stack, value);
	if (value_i < llen / 2)
		while (value_i--)
			do_rot(stack);
	else
		while (value_i++ <= llen - 1)
			do_rev_rot(stack);
}


//int				quick_sort(t_list **a, t_list **b,
//										int left, int right, char stack)
//{
//	int 		llen = ft_lstlen(stack == 'a' ? a : b);
//	int 		medi = llen / 2;
//	int 		k_val;
//
//	if (stack == 'b' && is_back_sorted(b))
//		return (0);
//	if (stack == 'a' && is_sorted(a))
//		return (0);
//
//	print_stacks(a, b);
//
//	k_val = get_value_for_index(stack == 'a' ? a : b, medi);
//	value_to_top(stack == 'a' ? a : b, k_val);
//	do_rot(stack == 'a' ? a : b);
//
//	print_stacks(a, b);
//	partition(a, b, k_val, stack);
//
//	print_stacks(a, b);
//	quick_sort(a, b, 0, ft_lstlen(b), 'b');
//	quick_sort(a, b, ft_lstlen(a), 0, 'a');
//}

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

int				partition(t_list **a, t_list **b, int m_index)
{
	int 		k_val;
	int 		top;
	int 		i;

	i = 0;
	top = *((int *)(*a)->content);
	k_val = get_value_for_index(a, m_index);


	value_to_top(a, k_val);
	do_rot(a);

	int llen = ft_lstlen(a);
	print_stacks(a, b);

	while (llen--)
	{
		top = *((int *)(*a)->content);
		if (top > k_val)
		{
			do_push(a, b, 'b');
			i++;
			continue;
		}
		do_rot(a);
		print_stacks(a, b);
	}
	do_rev_rot(a);
	do_push(a, b, 'b');
	print_stacks(a, b);
	return (i + 1);
}

void			quick_sort(t_list **a, t_list **b,
								int n)
{
	if (n == 1)
		return;
	int top_half_len = 0;
	int tmp = 0;
	int m_index = n / 2;

	print_stacks(a, b);
	top_half_len = partition(a, b, m_index);
	print_stacks(a, b);

	tmp = n - top_half_len;
	while (tmp--)
		do_rev_rot(a);

	print_stacks(a, b);
	tmp = top_half_len;
	while (tmp--)
		do_push(a, b, 'a');
	print_stacks(a, b);
	quick_sort(a, b, top_half_len);


	tmp = top_half_len;
	while (tmp--)
		do_rot(a);

	print_stacks(a, b);
	quick_sort(a, b, n - top_half_len);


	exit (0);
}

void 			sort_stacks(int *nums, unsigned arg_am)
{
	t_list		*a;
	t_list		*b;
	int 		ops;
	char 		st;

	/* ops = brute_force(&a, &b); */
	b = NULL;
	a = fill_a(nums, arg_am);

	quick_sort(&a, &b, ft_lstlen(&a));

	free_stacks(&a, &b);
}
