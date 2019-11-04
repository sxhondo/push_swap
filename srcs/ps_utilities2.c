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
	write(2, "Error", 5);
	exit(type);
}

t_list				*fill_a(int *nums, unsigned arg_am)
{
	unsigned		i;
	t_list			*node;
	t_list			*res;

	i = 0;
	res = NULL;
	while (i < arg_am)
	{
		if (!(node = ft_lstnew(&nums[i], sizeof(int))))
			return (NULL);
		ft_lstpushback(&res, node);
		i++;
	}
	return (res);
}

void				free_stacks(t_list **a, t_list **b)
{
	t_list			*curr;
	t_list			*next;

	curr = *a;
	while (curr)
	{
		next = curr->next;
		ft_memdel(&curr->content);
		free(curr);
		curr = next;
	}
	*a = NULL;
	curr = *b;
	while (curr)
	{
		next = curr->next;
		ft_memdel(&curr->content);
		free(curr);
		curr = next;
	}
	*b = NULL;
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
