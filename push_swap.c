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

int				get_key_value(t_list **stack, unsigned medi)
{

	t_list		*tmp;

	tmp = *stack;
	while (medi--)
		tmp = tmp->next;
	return (*((int *)tmp->content));
}

int				find_lower(t_list **stack, int k_val)
{
	t_list		*tmp;
	int 		i;
	int 		j;

	i = 1;
	j = 0;
	tmp = *stack;
	while (tmp)
	{
		if ((*(int *)tmp->content < k_val))
			return (i);
		if ((*(int *)tmp->content) == k_val)
			j = i;
//		if (gl == 'g' && (*(int *)tmp->content > k_val))
//			return (i);
		tmp = tmp->next;
		i++;
	}
	return (j ? j : 0);
}

/*	if (!(index = find_lower(a, k_val)))
		return (0);
	if (index <= llen / 2)
		while (--index)
		{
			ft_printf("\nrot");
			do_rot(a);
			print_stacks(a, b);
		}
	else if (index > llen / 2)
		while (index <= llen)
		{
			ft_printf("rev rot");
			do_rev_rot(a);
			print_stacks(a, b);
			index++;
		}*/


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

void 			sort_stacks(int *nums, unsigned arg_am)
{
	t_list		*a;
	t_list		*b;
	int 		ops;

	b = NULL;
	a = fill_a(nums, arg_am);

	ops = brute_force(&a, &b);

	int i = ft_lstlen(&b);
	ops += i;
	while (i--)
		do_push(&a, &b, 'a');
	print_stacks(&a, &b);
	ft_printf("Operations amount: %d\n", ops);
	free_stacks(&a, &b);
}
