/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:34:04 by sxhondo           #+#    #+#             */
/*   Updated: 2019/11/01 19:29:11 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list				*fill_a(int *nums, unsigned arg_am)
{
	unsigned		i;
	t_list			*node;
	t_list			*res;

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

void				free_stacks(t_list **a, t_list **b)
{
	t_list			*curr;
	t_list			*next;

	curr = *a;
	while (curr)
	{
		next = curr->next;
		ft_memdel(&curr->content);
		free(curr);
		curr = next;
	}
	*a = NULL;
	curr = *b;
	while (curr)
	{
		next = curr->next;
		ft_memdel(&curr->content);
		free(curr);
		curr = next;
	}
	*b = NULL;
}

static void			choose_operation2(t_list **a, t_list **b,
										unsigned op, unsigned char st)
{
	if (op & ROT)
	{
		if (st == 'a')
			do_rot(a);
		else if (st == 'b')
			do_rot(b);
		else
		{
			do_rot(a);
			do_rot(b);
		}
	}
	else if (op & REVROT)
	{
		if (st == 'a')
			do_rev_rot(a);
		else if (st == 'b')
			do_rev_rot(b);
		else
		{
			do_rev_rot(a);
			do_rev_rot(b);
		}
	}
}

static void			choose_operation1(t_list **a, t_list **b,
										unsigned op, unsigned char st)
{
	if (op & SWAP)
	{
		if (st == 'a')
			do_swap(a);
		else if (st == 'b')
			do_swap(b);
		else
		{
			do_swap(a);
			do_swap(b);
		}
	}
	else if (op & PUSH)
	{
		if (st == 'a')
			do_push(a, b, 'a');
		else if (st == 'b')
			do_push(a, b, 'b');
	}
	else
		choose_operation2(a, b, op, st);
}

void				apply_instruction(int *nums, t_list *ins,
														unsigned arg_am)
{
	t_list			*a;
	t_list			*b;
	unsigned		op;
	unsigned char	st;

	b = NULL;
	a = fill_a(nums, arg_am);
	while (ins)
	{
		op = ((t_op *)ins->content)->operation;
		st = ((t_op *)ins->content)->stack;
		choose_operation1(&a, &b, op, st);
		ins = ins->next;
	}
	ft_printf("%s\n", (is_sorted(&a, 0) && !b) ? "OK" : "KO");
	free_stacks(&a, &b);
}
