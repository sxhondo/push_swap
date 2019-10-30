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

static void			push_larger_half(t_list **a, t_list **b, int verb)
{
	int				min;
	int				head;

	min = find_minmax(a, 0);
	head = *((int *)(*a)->content);
	while (head != min)
	{
		print_push(a, b, 'b', verb);
		head = *((int *)(*a)->content);
	}
}

static void			quick_sort(t_list **a, t_list **b, int med, t_list **tab,
														int verb)
{
	t_list			*s;
	int				j;
	int				i;

	j = 0;
	if (ft_lstlen(b) <= 45)
		return ;
	while ((i = find_greater(b, med)) >= 0 && ++j)
	{
		rot_index_on_top(a, b, i, 'b', verb);
		print_push(a, b, 'a', verb);
	}
	if (!(s = ft_lstnew(&j, j)))
		return ;
	ft_lstadd(tab, s);
	quick_sort(a, b, find_medvalue(b), tab, verb);
}

static void			back_track(t_list **a, t_list **b, int verb)
{
	int				i;
	int				med;
	t_list			*tab;

	tab = NULL;
	while (1)
	{
		if (!*b)
			return ;
		med = find_medvalue(b);
		quick_sort(a, b, med, &tab, verb);
		i = insertion_sort(a, b, ft_lstlen(b), verb);
		while (i--)
		{
			print_push(a, b, 'a', verb);
			print_rot(a, b, 'a', verb);
		}
		if (!tab)
			break ;
		i = take_int_delete_node(&tab);
		while (i--)
			print_push(a, b, 'b', verb);
	}
	push_larger_half(a, b, verb);
	back_track(a, b, verb);
}

static void			sort_small_stack(t_list **a, t_list **b, int verb)
{
	int				tmp;

	while (!is_sorted(a, 0))
	{
		if (ft_lstlen(a) == 2 && (*((int *)(*a)->content) >
						(*((int *)(*a)->next->content))))
		{
			print_swap(a, b, 'a', verb);
			break;
		}
		tmp = find_minmax(a, 0);
		rot_index_on_top(a, b, get_index_for_value(a, tmp), 'a', verb);
		print_push(a, b, 'b', verb);
	}
	if (b)
	{
		tmp = ft_lstlen(b);
		while (tmp--)
			print_push(a, b, 'a', verb);
	}
}

void				sort_stacks(int *nums, unsigned arg_am, int verb)
{
	t_list			*a;
	t_list			*b;
	int				tmp;
	int				i;

	b = NULL;
	a = fill_a(nums, arg_am);
	if (ft_lstlen(&a) <= 5)
		sort_small_stack(&a, &b, verb);
	else if (!is_sorted(&a, 0))
	{
		i = find_medvalue(&a);
		while ((tmp = find_less(&a, i)) > -1)
		{
			rot_index_on_top(&a, &b, tmp, 'a', verb);
			print_push(&a, &b, 'b', verb);
		}
		back_track(&a, &b, verb);
	}
	if (verb == 1 || verb == 3)
		print_hor(&a, &b);
//	print_hor(&a, &b);
	free_ins(&a);
}
