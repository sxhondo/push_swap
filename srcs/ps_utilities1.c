/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilities1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:18:53 by sxhondo           #+#    #+#             */
/*   Updated: 2019/10/30 19:18:53 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_index_for_value(t_list **stack, int value)
{
	int			i;
	t_list		*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) == value)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int				find_less(t_list **stack, int min)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) < min)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int				find_greater(t_list **stack, int val)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) > val)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int				find_minmax(t_list **stack, int mode)
{
	t_list		*i;
	t_list		*j;
	int			curr;

	i = *stack;
	while (i)
	{
		curr = *((int *)i->content);
		j = *stack;
		while (!mode && j && *((int *)j->content) >= curr)
			j = j->next;
		while (mode && j && *((int *)j->content) <= curr)
			j = j->next;
		if (!j)
			return (curr);
		i = i->next;
	}
	return (-1);
}

int				is_sorted(t_list **stack, int mode)
{
	t_list		*tmp;

	tmp = *stack;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if (!mode && *((int *)tmp->content) < *((int *)tmp->next->content))
			tmp = tmp->next;
		else if (mode && *((int *)tmp->content) > *((int *)tmp->next->content))
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
