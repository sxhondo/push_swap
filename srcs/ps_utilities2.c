/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:21:58 by sxhondo           #+#    #+#             */
/*   Updated: 2019/10/30 19:21:59 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				put_error(int type, t_list **stack)
{
	if (type == 3)
		free_ins(stack);
	write(2, "Error\n", 6);
	exit(type);
}

int					take_int_delete_node(t_list **tab)
{
	int				j;
	t_list			*next;
	t_list			*curr;

	if (!*tab)
		return (0);
	curr = *tab;
	next = curr->next;
	j = *((int *)curr->content);
	ft_memdel(&curr->content);
	free(curr);
	*tab = next;
	return (j);
}

int					rot_index_on_top(t_list **stack, int index,
														int verb, char dst)
{
	int				llen;

	llen = ft_lstlen(stack);
	if (index < 0)
		return (0);
	if (index <= llen / 2)
	{
		while (index-- > 0)
			print_rot(dst == 'a' ? stack : NULL,
					dst == 'b' ? stack : NULL, dst, verb);
	}
	else
	{
		while (index++ <= llen - 1)
			print_rev_rot(dst == 'a' ? stack : NULL,
					dst == 'b' ? stack : NULL, dst, verb);
	}
	return (1);
}

void				optimised_rot(t_list **a, t_list **b, int rra, int verb)
{
	int				i;

	i = ft_lstlen(b) / 2;
	while (i)
	{
		print_rrr(a, b, verb);
		rra--;
		i--;
	}
	while (rra--)
		print_rev_rot(a, b, 'a', verb);
}
