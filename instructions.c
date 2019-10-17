/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:28:46 by sxhondo           #+#    #+#             */
/*   Updated: 2019/09/30 18:28:47 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void			do_swap(t_list **stack)
{
	t_list		*tmp;

	if (!*stack || ft_lstlen(stack) < 1)
		return;
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
}


void			do_push(t_list **a, t_list **b, char in)
{
	t_list		*ptr;

	if (in == 'a')
	{
		ptr = *b;
		if (!ptr)
			return ;
		*b = (*b)->next;
		ptr->next = *a;
		*a = ptr;
	}
	else if (in == 'b')
	{
		ptr = *a;
		if (!ptr)
			return ;
		*a = (*a)->next;
		ptr->next = *b;
		*b = ptr;
	}
}

void			do_rot(t_list **stack)
{
	t_list		*ptr;
	t_list		*next;

	if (!*stack || ft_lstlen(stack) == 1)
		return;
	ptr = *stack;
	next = ptr->next;
	ptr->next = NULL;
	*stack = next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = ptr;
	*stack = next;
}

void			do_rev_rot(t_list **stack)
{
	t_list		*ptr;
	t_list		*save;

	if (!*stack || ft_lstlen(stack) == 1)
		return;
	ptr = *stack;
	while (ptr->next->next)
		ptr = ptr->next;
	save = ptr->next;
	ptr->next = NULL;
	save->next = *stack;
	*stack = save;
}