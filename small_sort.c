/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:31:37 by sxhondo           #+#    #+#             */
/*   Updated: 2019/10/30 19:31:38 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				sort_two(t_list **a_s, t_list **b_s, char dst, int verb)
{
	int				a;
	int				b;

	a = dst == 'a' ? *((int *)(*a_s)->content) : *((int *)(*b_s)->content);
	b = dst == 'a' ? *((int *)(*a_s)->next->content) :
											*((int *)(*b_s)->next->content);
	if (a > b)
		print_swap(a_s, b_s, dst, verb);
}

void				sort_three(t_list **a_s, t_list **b_s, int verb)
{
	int				a;
	int				b;
	int				c;

	while (!is_sorted(b_s, 0))
	{
		a = *((int *)(*b_s)->content);
		b = *((int *)(*b_s)->next->content);
		c = *((int *)(*b_s)->next->next->content);
		if (a > b && a > c && b < c)
			print_rot(a_s, b_s, 'b', verb);
		if (a > b && a > c && b > c)
		{
			print_swap(a_s, b_s, 'b', verb);
			print_rev_rot(a_s, b_s, 'b', verb);
		}
		if (a > b && a < c && b < c)
			print_swap(a_s, b_s, 'b', verb);
		if (a < b && a > c && b > c)
			print_rev_rot(a_s, b_s, 'b', verb);
		if (a < b && a < c && b > c)
		{
			print_swap(a_s, b_s, 'b', verb);
			print_rot(a_s, b_s, 'b', verb);
		}
	}
}

int					insertion_sort(t_list **a, t_list **b, int n, int verb)
{
	int				tmp;

	while (n > 3)
	{
		tmp = find_minmax(b, 0);
		rot_index_on_top(a, b, get_index_for_value(b, tmp), 'b', verb);
		print_push(a, b, 'a', verb);
		print_rot(a, b, 'a', verb);
		n--;
	}
	if (n == 3)
	{
		sort_three(a, b, verb);
		return (n);
	}
	else if (n == 2)
	{
		sort_two(a, b, 'b', verb);
		return (n);
	}
	else
		return (1);
}
