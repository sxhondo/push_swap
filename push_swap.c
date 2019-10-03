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

int				get_key_value(t_list **stack, unsigned index)
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
		tmp = tmp->next;
		i++;
	}
	return (0);
}


/* */
int 		sort(t_list **a, t_list **b, int low, int high,
													int index_m, int k_val)
{
	int 	i;
	int 	t;

	t = 0;
	ft_printf("KEY_VALUE: %d\n", k_val);
	print_stacks(a, b);
	while (*((int*)(*a)->content) < k_val)
		do_rot(a);
	do_push(a, b, 'b');
	quick_sort(a, b, low, high, index_m, k_val);
}

void			quick_sort(t_list **a, t_list **b,
										int low, int high)
{
	int 		index_m;
	int 		key_v;

	/* pre_sort() must fill stack (b) with values lower than med-value from (a)
	 * */

//	pre_sort();
	if (low < high)
	{
		index_m = (high - low) / 2;
		key_v = get_key_value(a, index_m);
		//sort_one();
		quick_sort(a, b, low, index_m - 1); //sort (a)
		quick_sort(a, b, index_m + 1, high); //sort (b)
	}

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
	sort_group(&a, &b, 0, ft_lstlen(&a));

	print_stacks(&a, &b);
	free_stacks(&a, &b);
}
