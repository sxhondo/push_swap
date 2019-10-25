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
		if (*str == 'r' && bytes == 4 && ++str)
		{
			op->operation |= REVROT;
			op->stack = is_rotate(*str);
		}
		else if (bytes == 3)
		{
			op->operation |= ROT;
			op->stack = is_rotate(*str);
		}
	}
}

static t_op		*parse_instruction(char *buf, int bytes)
{
	t_op		*ops;

	if (!(ops = (t_op*)malloc(sizeof(t_op))))
		return (NULL);
	ops->operation = 0;
	ops->stack = 0;
	get_instruction(buf, ops, bytes);
	if (!ops->stack || !ops->operation)
	{
		put_error(5);
		free(ops);
		return (NULL);
	}
	return (ops);
}

t_list			*read_instructions()
{
	char 		buf[10];
	int 		bytes;
	t_op		*ops;
	t_list		*node;
	t_list		*instr;

	instr = NULL;
	while((bytes = read(0, buf, 10)))
	{
		buf[bytes] = '\0';
		ft_printf("Q: %s\n", buf);
		if (bytes <= 2 || bytes > 4 || !(ops = parse_instruction(buf, bytes)))
		{
			put_error(4);
			free_ins(&instr);
			return (NULL);
		}
		if (!(node = ft_lstnew(ops, sizeof(ops))))
			return (NULL);
		ft_lstpushback(&instr, node);
		free (ops);
	}
	return (instr);
}