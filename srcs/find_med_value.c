/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_med_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:12:49 by sxhondo           #+#    #+#             */
/*   Updated: 2019/10/30 19:12:50 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		arithmetic_mean(t_list **stack, int llen)
{
	int			le;
	int64_t		res;
	t_list		*p;

	le = llen;
	res = 0;
	p = *stack;
	while (p && le--)
	{
		res += *((int *)p->content);
		p = p->next;
	}
	res /= llen;
	if (res >= INT32_MAX)
		put_error(3, stack);
	return ((int)res);
}

static int		find_match(t_list **stack, int value)
{
	t_list		*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				find_medvalue(t_list **stack, int len)
{
	int			res;
	int			i;

	res = arithmetic_mean(stack, len);
	i = 0;
	while (res)
	{
		res += i;
		if ((find_match(stack, res)))
			return (res);
		res -= i;
		if ((find_match(stack, res)))
			return (res);
		i++;
	}
	return (-1);
}
