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
*/

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

void			compare_inside(t_list **a, t_list **b, char stack, int memlen)
{
	int 		top;
	int			top_next;


	print_stacks(a, b);
	if (!(*a) || !(*b))
	{
		while (memlen--)
			do_push(a, b, stack == 'a' ? 'a' : 'b');
		return;
	}
	top = stack == 'a' ? *((int *)(*a)->content) : *((int *)(*b)->content);
	if (stack == 'a')
	{
		if (ft_lstlen(stack == 'a' ? a : b) == 2)
			top_next = *((int *)(*a)->next->content);
		else if (ft_lstlen(stack == 'a' ? a : b) == 1)
			top_next = top + 1;
		else
			top_next = *((int *)(*a)->next->next->content);
	}
	else
	{
		if (ft_lstlen(stack == 'b' ? b : a) == 2)
			top_next = *((int *)(*b)->next->content);
		else if (ft_lstlen(stack == 'b' ? b : a) == 1)
			top_next = top + 1;
		else
			top_next = *((int *)(*b)->next->next->content);
	}

	if (top < top_next)
	{
		do_push(a, b, stack == 'a' ? 'b' : 'a');
		print_stacks(a, b);
		if (stack == 'a' && (*a))
			value_to_top(a, top_next);
		else if (stack == 'b' && (*b))
			value_to_top(b, top_next);
	}
	else
	{
		value_to_top(stack == 'a' ? a : b, top_next);
		do_push(a, b, stack == 'a' ? 'b' : 'a');
		print_stacks(a, b);
//		value_to_top(stack == 'a' ? a : b, top);
		if (stack == 'a' && (*a))
			value_to_top(a, top);
		else if (stack == 'b' && (*b))
			value_to_top(b, top);
	}
	compare_inside(a, b, stack, memlen);
}

int				find_min_max(t_list **stack, int mix) /* 0 - min, 1 - max */
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

void			merge_stacks(t_list **a, t_list **b)
{
	t_list		*p_a;
	t_list		*p_b;
	int 		top_a;
	int 		top_b;

	p_a = *a;
	p_b = *b;
	if (!p_a || !p_b)
		return;
	top_a = *((int *)p_a->content);
	top_b = *((int *)p_b->content);

	print_stacks(a, b);
	if (top_b > find_min_max(a, 1))
	{
		value_to_top(a, find_min_max(a, 1));
		print_stacks(a, b);
		do_rot(a);
		do_push(a, b, 'a');
		print_stacks(a, b);
		merge_stacks(a, b);
	}
	if (top_a > top_b)
	{
		do_push(a, b, 'a');
		do_rot(a);
		print_stacks(a, b);
	}
	else
	{
		do_rot(a);
	}
	merge_stacks(a, b);

}

int 			is_double_sorted(t_list **stack)
{
	t_list		*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (*((int *)tmp->content) < *((int *)tmp->next->content))
		{
			tmp = tmp->next;
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (1);
}

void			double_compare(t_list **stack, int prev_a, int prev_b, int mm)
{
	int 		a;
	int 		b;

	if (!mm)
		return;
	a = *((int *)(*stack)->content);
	b = *((int *)(*stack)->next->content);
	if (is_double_sorted(stack) || a == prev_a || b == prev_b)
		return;
	if (a > b)
	{
		do_swap(stack);
		do_rot(stack);
		do_rot(stack);
	}
	else
	{
		do_rot(stack);
		do_rot(stack);
	}
	prev_a = a;
	prev_b = b;
	double_compare(stack, prev_a, prev_b, --mm);

}

void			merge_sort(t_list **a, t_list **b)
{
	int 		medi = ft_lstlen(a) / 2;
	int 		mm;

	if (is_sorted(a))
		return;

	print_stacks(a, b);
	while (medi--)
	{
		do_push(a, b, 'b');
		print_stacks(a, b);
	}

	mm = ft_lstlen(a);
	double_compare(a, -1, -1, mm);
	mm = ft_lstlen(b);
	double_compare(b, -1, -1, mm);

	print_stacks(a, b);

	mm = ft_lstlen(a);
	compare_inside(a, b, 'a', mm);
	print_stacks(a, b);
	mm = ft_lstlen(b);


	compare_inside(a, b, 'b', mm); //a aA a a a
	print_stacks(a, b);


	value_to_top(a, find_min_max(a, 0));
	value_to_top(b, find_min_max(b, 0));
	print_stacks(a, b);

//	value_to_top(a, find_min_max(a, 0));
//	print_stacks(a, b);
//	value_to_top(b, find_min_max(b, 0));
//	print_stacks(a, b);
//
//	merge_stacks(a, b);
//	print_stacks(a, b);
//
//	value_to_top(a, find_min_max(a, 0));
//	print_stacks(a, b);






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
	merge_sort(&a, &b);
//	print_stacks(&a, &b);
	free_stacks(&a, &b);
}
