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

void				sort_two(t_list **a, t_list **b, char dst, int verb)
{
	int				c;
	int				n;

	if (dst == 'a')
	{
		c = *((int *)(*a)->content);
		n = *((int *)(*a)->next->content);
	}
	else
	{
		c = *((int *)(*b)->content);
		n = *((int *)(*b)->next->content);
	}
	if (c > n)
		print_swap(a, b, dst, verb);
}

void				sort_small_stack(t_list **a, t_list **b, int verb)
{
	int				tmp;

	while (!is_sorted(a, 0))
	{
		if (ft_lstlen(a) == 2)
		{
			sort_two(a, b, 'a', verb);
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

void				insertion_sort(t_list **a, t_list **b, int verb)
{
	int				minmax[2];
	int				ind[2];
	int				min_way;
	int				max_way;
	int				i;

	i = 0;
	while (*b)
	{
		minmax[0] = find_minmax(b, 0);
		minmax[1] = find_minmax(b, 1);
		ind[0] = get_index_for_value(b, minmax[0]);
		ind[1] = get_index_for_value(b, minmax[1]);
		min_way = ind[0] < ft_lstlen(b) / 2 ? ind[0] : ft_lstlen(b) - ind[0];
		max_way = ind[1] < ft_lstlen(b) / 2 ? ind[1] : ft_lstlen(b) - ind[1];
		rot_index_on_top(b, min_way < max_way ? ind[0] : ind[1], verb, 'b');
		print_push(a, b, 'a', verb);
		minmax[0] == *((int *)(*a)->content) ? print_rot(a, b, 'a', verb) : i++;
	}
	while (i--)
		print_rot(a, b, 'a', verb);
}
