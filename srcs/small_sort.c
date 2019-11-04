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

void				sort_three(t_list **a, t_list **b, int verb)
{
	int				abc[3];
	int 			q, w, e;

//	print_hor(a, b);
	while (!is_sorted(b, 1))
	{
//		abc[0] = *((int *)(*b)->content);
//		abc[1] = *((int *)(*b)->next->content);
//		abc[2] = *((int *)(*b)->next->next->content);
		q = *((int *)(*b)->content);
		w = *((int *)(*b)->next->content);
		e = *((int *)(*b)->next->next->content);

		if (q > w && q > e && w < e)
		{
			print_swap(a, b, 'b', verb);
			print_rot(a, b, 'b', verb);
//			print_hor(a, b);
		}
		if (q < w && w < e && w < e)
		{
			print_swap(a, b, 'b', verb);
			print_rev_rot(a, b, 'b', verb);
		}
		if (q < w && q > e && w > q)
			print_swap(a, b, 'b', verb);
		if (q > w && q < e && w < q)
			print_rev_rot(a, b, 'b', verb);
		if (q < w && q < e && w > e)
			print_rot(a, b, 'b', verb);

	}
}

//int					rot_min_on_top_b(t_list **a, t_list **b, int verb, int i)
//{
//	int				llen;
//	int 			min;
//	int 			index;
//
//	llen = ft_lstlen(b);
//	min = find_minmax(b, 0);
//	index = get_index_for_value(b, min);
//	print_hor(a, b);
//	if (index < 0)
//		return (0);
//	if (index <= llen / 2)
//	{
//		while (index-- > 0)
//		{
//			print_rot(a, b, 'b', verb);
//		}
//	}
//	else
//	{
//		while (index++ <= llen - 1)
//			print_rev_rot(a, b, 'b', verb);
//	}
//	return (1);
//}

int					insertion_sort(t_list **a, t_list **b, int n, int verb)
{
	int 			len;
	int 			tmp;

	len = n;
//	print_hor(a, b);
	while(n > 3)
	{
		tmp = find_minmax(b, 1);
		tmp = get_index_for_value(b, tmp);
		rot_index_on_top(b, tmp, verb, 'b');
		print_push(a, b, 'a', verb);
		n--;
	}
//	print_hor(a, b);
	if (n == 3)
		sort_three(a, b, verb);
	if (n == 2)
	{
		if ((*b)->content < (*b)->next->content)
			print_swap(a, b, 'b', verb);
	}
	tmp = ft_lstlen(b);
	while (tmp--)
		print_push(a, b, 'a', verb);
	while (len--)
		print_rot(a, b, 'a', verb);
//	print_hor(a, b);
}
