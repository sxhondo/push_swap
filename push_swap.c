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

int 			is_sorted(t_list **stack)
{
	t_list		*tmp;

	tmp = *stack;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if (*((int *)tmp->content) < *((int *)tmp->next->content))
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int			catch_swap(t_list **a, t_list **b, char stack)
{
	int 	top;
	int 	top_next;

	top = 0;
	top_next = 0;
	if (((*a) || (*b)) && ft_lstlen(stack == 'a' ? a : b) == 2)
	{
		top = stack == 'a' ? *((int *)(*a)->content)
				: *((int *)(*b)->content);
		top_next = stack == 'a' ? *((int *)(*a)->next->content)
				: *((int *)(*b)->next->content);
	}
	if (top > top_next)
	{
		do_swap(stack == 'a' ? a : b);
		ft_printf("s%c\n", stack == 'a' ? 'a' : 'b'); ops++;
		return (1);
	}
	return (0);

}

int 			check_max(t_list **stack, int value)
{
	t_list		*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) > value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				partition(t_list **a, t_list **b,
						int m_index, char stack)
{
	int 		k_val;
	int 		i;

	if (is_sorted(stack == 'a' ? a : b))
		return (0);
	k_val = get_value_for_index(stack == 'a' ? a : b, m_index);
	if (check_max(stack == 'a' ? a : b, k_val))
	{
		i = ft_lstlen(stack == 'a' ? a : b) - 1;
		k_val = get_value_for_index(stack == 'a' ? a : b, i);
	}
	i = 0;
	while ((rot_to_top(stack == 'a' ? a : b, k_val, stack)))
	{
		do_push(a, b, stack == 'a' ? 'b' : 'a');
		ft_printf("p%c\n", stack == 'a' ? 'b' : 'a'); ops++;
		i++;
	}
//	print_stacks(a, b);
	return (i);
}

int 				count_connections(t_list **stack)
{
	int 			i;
	t_list			*tmp;

	i = 0;
	tmp = *stack;
	while (tmp->next)
	{
		if (*((int *)tmp->content) < *((int *)tmp->next->content))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void				smart_swap(t_list **stack, char st)
{
	t_list			*tmp;
	int 			top;
	int 			cur;
	int 			nex;
	int 			i;

	i = 0;
	tmp = *stack;
	top = cur = *((int *)tmp->content);
	nex = *((int *)tmp->next->content);
	while (tmp && cur < nex)
	{
		cur = *((int *)tmp->content);
		nex = *((int *)tmp->next->content);
		tmp = tmp->next;
		i++;
	}
//	print_stacks(stack, NULL);
	rot_to_top(stack, cur, st);
//	print_stacks(stack, NULL);
	do_swap(stack);
//	print_stacks(stack, NULL);
	rot_to_top(stack, top, st);
//	print_stacks(stack, NULL);

}

void				quick_sort(t_list **a, t_list **b,
						int n, char stack)
{

	if (catch_swap(a, b, stack))
		return;
	//debug it
//	if (count_connections(stack == 'a' ? a : b) == (n - 2))
//		smart_swap(stack == 'a' ? a : b, stack);
	if (is_sorted(stack == 'a' ? a : b))
		return;
	if (n == 0)
		return;
	int top_half_len = 0;
	int tmp = 0;
	int m_index = n - 1;


	top_half_len = partition(a, b, m_index, stack);
//	print_stacks(a, b);

	catch_swap(a, b, stack);

//	tmp =  n - top_half_len;
//	while (tmp--)
//	{
//		do_rev_rot(stack == 'a' ? a : b); ft_printf("rr%c\n", stack);
//	}

	tmp = top_half_len;
	while (tmp--)
		{do_push(a, b, stack); ft_printf("p%c\n", stack); ops++;}
	tmp = top_half_len - 1 ? top_half_len - 1 :
							ft_lstlen(stack == 'a' ? a : b);
	quick_sort(a, b, tmp, stack);
}

void 			sort_stacks(int *nums, unsigned arg_am)
{
	int 		llen;
	t_list		*a;
	t_list		*b;

	ops = 0;
	b = NULL;
	a = fill_a(nums, arg_am);
	llen = ft_lstlen(&a);

//	brute_force(&a, &b);

	partition(&a, &b, 0, 'a');
	quick_sort(&a, &b, ft_lstlen(&a), 'a');
//	print_stacks(&a, &b);
	quick_sort(&a, &b, ft_lstlen(&b), 'b');
//	print_stacks(&a, &b);
	for (int i = ft_lstlen(&b); i; i--)
	{
		do_rev_rot(&b);
		do_push(&a, &b, 'a'); ft_printf("pa\n"); ops++;
	}
//	print_stacks(&a, &b);
//	ft_printf("\n[%d]\n", ops);
	free_stacks(&a, &b);
}
