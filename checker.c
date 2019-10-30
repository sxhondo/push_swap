/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:54:33 by sxhondo           #+#    #+#             */
/*   Updated: 2019/09/26 19:54:33 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		get_instruction(char *str, t_op *op, int bytes)
{
	if (*str == 's' && ++str)
	{
		op->operation |= SWAP;
		op->stack = is_swap(*str);
	}
	else if (*str == 'p' && ++str)
	{
		op->operation |= PUSH;
		op->stack = is_push(*str);
	}
	else if (*str == 'r' && ++str)
	{
		if (*str == 'r' && bytes == 3 && ++str)
		{
			op->operation |= REVROT;
			op->stack = is_rotate(*str);
		}
		else if (bytes == 2)
		{
			op->operation |= ROT;
			op->stack = is_rotate(*str);
		}
	}
}

static t_op		*parse_instruction(char *buf)
{
	t_op		*ops;
	int 		len;

	if ((len = ft_strlen(buf)) > 4 || len == 1)
		return (NULL);
	if (!(ops = (t_op*)malloc(sizeof(t_op))))
		return (NULL);
	ops->operation = 0;
	ops->stack = 0;
	get_instruction(buf, ops, len);
	if (!ops->stack || !ops->operation)
	{
		free(ops);
		return (NULL);
	}
	return (ops);
}

t_list			*read_instructions()
{
	t_op		*ops;
	t_list		*node;
	t_list		*instr;
	char 		*buf;
	int 		ret;

	instr = NULL;
	while ((get_next_line(0, &buf)))
	{
		if (!(ops = parse_instruction(buf)))
		{
			ft_strdel(&buf);
			free_ins(&instr);
			write(2, "Error", 5);
			exit (1);
		}
		if (!(node = ft_lstnew(ops, sizeof(ops))))
			return (NULL);
		ft_lstpushback(&instr, node);
		ft_strdel(&buf);
		free (ops);
	}
	return (instr);
}