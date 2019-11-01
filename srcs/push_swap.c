/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:09:19 by sxhondo           #+#    #+#             */
/*   Updated: 2019/11/01 19:43:07 by sxhondo          ###   ########.fr       */
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

static void			quick_sort(t_list **a, t_list **b, t_list **tab, int verb)
{
	int				med;
	t_list			*s;
	int				j;
	int				i;

	j = 0;
	if (ft_lstlen(b) <= 45)
		return ;
	med = find_medvalue(b);
	while ((i = find_greater(b, med)) >= 0 && ++j)
	{
		rot_index_on_top(b, i, verb, 'b');
		print_push(a, b, 'a', verb);
	}
	if (!(s = ft_lstnew(&j, j)))
	{
		free_ins(tab);
		return ;
	}
	ft_lstadd(tab, s);
	quick_sort(a, b, tab, verb);
}

static void			back_track(t_list **a, t_list **b, int verb)
{
	int				i;
	t_list			*tab;

	tab = NULL;
	while (1)
	{
		if (!*b)
			return ;
		quick_sort(a, b, &tab, verb);
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
			break ;
		}
		tmp = find_minmax(a, 0);
		rot_index_on_top(a, get_index_for_value(a, tmp), verb, 'a');
		print_push(a, b, 'b', verb);
	}
	if (*b)
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
			rot_index_on_top(&a, tmp, verb, 'a');
			print_push(&a, &b, 'b', verb);
		}
		back_track(&a, &b, verb);
	}
	if (verb == 1 || verb == 3)
		print_hor(&a, &b);
	free_ins(&a);
}
