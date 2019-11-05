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

static void			quick_sort(t_list **a, t_list **b, t_list **tab, int verb)
{
	int				med;
	t_list			*s;
	int				j;
	int				i;

	j = 0;
	if (ft_lstlen(b) <= 30)
		return ;
	med = find_medvalue(b, ft_lstlen(b));
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

static int			push_larger_half(t_list **a, t_list **b, int max, int verb)
{
	int				i;
	int				head;
	int				new_pi;

	new_pi = find_medvalue(a, max);
	head = *((int *)(*a)->content);
	i = 0;
	while (max--)
	{
		if (head < new_pi)
			print_push(a, b, 'b', verb);
		else if (++i)
			print_rot(a, b, 'a', verb);
		head = *((int *)(*a)->content);
	}
	return (i);
}

static void			sort(t_list **a, t_list **b, int verb, t_list *tab)
{
	int				i;
	if (is_sorted(a, 0) && !*b)
		return ;
	while (1)
	{
		quick_sort(a, b, &tab, verb);
		insertion_sort(a, b, verb);
		if ((i = take_int_delete_node(&tab)) == 0)
			break ;
		while (i--)
			print_push(a, b, 'b', verb);
	}
	i = get_index_for_value(a, find_minmax(a, 0));
	if (i >= ft_lstlen(a) / 2)
	{
		i = push_larger_half(a, b, i, verb);
		optimised_rot(a, b, i, verb);
	}
	else
		while (i--)
			print_push(a, b, 'b', verb);
	sort(a, b, verb, tab);
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
		i = find_medvalue(&a, ft_lstlen(&a));
		while ((tmp = find_less(&a, i)) > -1)
		{
			rot_index_on_top(&a, tmp, verb, 'a');
			print_push(&a, &b, 'b', verb);
		}
		sort(&a, &b, verb, NULL);
	}
	if (verb == 1 || verb == 3)
		print_hor(&a, &b);
	free_ins(&a);
}
