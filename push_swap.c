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

/*
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
*/


//void			merge_sort(t_list **a, t_list **b)
//{
//	int 		medi = ft_lstlen(a) / 2;
//	int 		i = medi;
//	print_stacks(a, b);
//	while (medi--)
//	{
//		do_push(a, b, 'b');
//		print_stacks(a, b);
//	}
//	while (i--)
//	{
//		int top_a = *((int *)(*a)->content);
//		int top_b = *((int *)(*b)->content);
//		if (top_a > top_b)
//		{
//			do_push(a, b, 'b');
//			do_rot(b);
//			do_push(a, b, 'a');
//			do_rot(a);
//			print_stacks(a, b);
//		}
//	}
//	print_stacks(a, b);
//
//
//}

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

void			partition(t_list **a, t_list **b, int k_val, char stack)
{
	int 		top;
	int 		i;

	i = 0;
	top = stack == 'a' ? *((int *)(*a)->content) : *((int *)(*b)->content);
	while (top != k_val)
	{
		top = stack == 'a' ? *((int *)(*a)->content) : *((int *)(*b)->content);
		if (top < k_val)
		{
			do_push(a, b, stack == 'a' ? 'b' : 'a');
			i++;
			continue;
		}
		if (top == k_val)
		{
			do_push(a, b, stack == 'a' ? 'b' : 'a');
			i++;
			break;
		}
		do_rot(stack == 'a' ? a : b);
		print_stacks(a, b);
	}
//	if (stack == 'b')
//		while (i--)
//			do_push(a, b, 'b');
	print_stacks(a, b);

}

void			pre_sort(t_list **a, t_list **b)
{
	int 		llen = ft_lstlen(a);
	int 		medi = llen / 2;
	int 		k_val;


	k_val = get_value_for_index(a, medi);
	value_to_top(a, k_val);
	do_rot(a);

	print_stacks(a, b);
	partition(a, b, k_val, 'a');
}

int				quick_sort(t_list **a, t_list **b,
										int left, int right, char stack)
{
	int 		llen = ft_lstlen(stack == 'a' ? a : b);
	int 		medi = llen / 2;
	int 		k_val;

	if (stack == 'b' && is_back_sorted(b))
		return (0);
	if (stack == 'a' && is_sorted(a))
		return (0);

	print_stacks(a, b);

	k_val = get_value_for_index(stack == 'a' ? a : b, medi);
	value_to_top(stack == 'a' ? a : b, k_val);
	do_rot(stack == 'a' ? a : b);

	print_stacks(a, b);
	partition(a, b, k_val, stack);

	print_stacks(a, b);
	quick_sort(a, b, 0, ft_lstlen(b), 'b');
	quick_sort(a, b, ft_lstlen(a), 0, 'a');
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

	pre_sort(&a, &b);
	quick_sort(&a, &b, 0, ft_lstlen(&a), 'b');
//	print_stacks(&a, &b);

//	merge_sort(&a, &b);
//	print_stacks(&a, &b);
	free_stacks(&a, &b);
}
