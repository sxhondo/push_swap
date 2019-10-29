/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:09:19 by sxhondo           #+#    #+#             */
/*   Updated: 2019/10/29 21:09:20 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_larger_half(t_list **a, t_list **b)
{
	int 			min;
	int 			head;

	min = find_minmax(a, 0);
	head = *((int *)(*a)->content);
	while (head != min)
	{
		do_push(a, b, 'b');
		head = *((int *)(*a)->content);
		ft_printf("pb\n");
	}
}

static void			quick_sort(t_list **a, t_list **b, int med, t_list **tab)
{
	t_list			*s;
	int 			j;
	int 			i;

	j = 0;
	if (ft_lstlen(b) <= 45)
		return;
	while ((i = find_greater(b, med)) >= 0 && ++j)
	{
		rot_index_on_top(b, i, 'b');
		print_push(a, b, 'a');
	}
	if (!(s = ft_lstnew(&j, j)))
		return;
	ft_lstadd(tab, s);
	quick_sort(a, b, find_medvalue(b), tab);
}

static void			back_track(t_list **a, t_list **b)
{
	int 			i;
	int 			j;
	int 			med;
	t_list			*tab;

	tab = NULL;
	while (1)
	{
		if (!*b)
			return;
		med = find_medvalue(b);
		quick_sort(a, b, med, &tab);
		i = insertion_sort(a, b, ft_lstlen(b));
		while (i--)
		{
			print_push(a, b, 'a');
			print_rot(a, b, 'a');
		}
		if (!tab)
			break;
		j = take_int_delete_node(&tab);
		while (j--)
			print_push(a, b, 'b');
	}
	push_larger_half(a, b);
	back_track(a, b);
}

static void		sort_small_stack(t_list **a, t_list **b)
{
	int 		tmp;

	while (!is_sorted(a, 0))
	{
		tmp = find_minmax(a, 0);
		rot_index_on_top(a, get_index_for_value(a, tmp), 'a');
		do_push(a, b, 'b');
	}
	if (b)
	{
		tmp = ft_lstlen(b);
		while (tmp--)
			print_push(a, b, 'a');
	}
}

void 			sort_stacks(int *nums, unsigned arg_am)
{
	t_list		*a;
	t_list		*b;
	int 		tmp;
	int 		i;

	b = NULL;
	a = fill_a(nums, arg_am);
	if (ft_lstlen(&a) <= 5)
		sort_small_stack(&a, &b);
	else
	{
		i = find_medvalue(&a);
		while ((tmp = find_less(&a, i)) > -1)
		{
			rot_index_on_top(&a, tmp, 'a');
			print_push(&a, &b, 'b');
		}
		back_track(&a, &b);
	}
	print_hor(&a, &b);
	free_ins(&a);
}
