/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:34:04 by sxhondo           #+#    #+#             */
/*   Updated: 2019/09/30 18:34:07 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					print_hor(t_list **a, t_list **b)
{
	t_list				*p_a;
	t_list				*p_b;

	p_a = a ? *a : NULL;
	p_b = b ? *b : NULL;

	ft_printf("A: ");
	while (p_a)
	{
		ft_printf("%3d ", *((int*)p_a->content));
		p_a = p_a->next;
	}
	ft_printf("\nB: ");
	while (p_b)
	{
		ft_printf("%3d ", *((int*)p_b->content));
		p_b = p_b->next;
	}
	ft_printf("\n\n");
}

void					print_ver(t_list **a, t_list **b)
{
	t_list				*p_a;
	t_list				*p_b;

	p_a = a ? *a : NULL;
	p_b = b ? *b : NULL;
	ft_printf("\na\tb\n---------\n");
	while (p_a || p_b)
	{
		if (p_a)
		{
			ft_printf("%d", *((int *)p_a->content));
			p_a = p_a->next;
		}
		ft_printf("\t");
		if (p_b)
		{
			ft_printf("%d", *((int *)p_b->content));
			p_b = p_b->next;
		}
		ft_printf("\n");
	}
}

void					free_stacks(t_list **a, t_list **b)
{
	t_list				*curr;
	t_list				*next;

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

t_list					*fill_a(int *nums, unsigned arg_am)
{
	int 				i;
	t_list				*node;
	t_list				*res;

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

static void				apply_instruction(int *nums, t_list *ins, unsigned arg_am)
{
	t_list				*a;
	t_list				*b;
	unsigned 			op;
	unsigned char 		st;

	b = NULL;
	a = fill_a(nums, arg_am);
	print_ver(&a, &b);
	while (ins)
	{
		op = ((t_op *)ins->content)->operation;
		st = ((t_op *)ins->content)->stack;
		ft_printf("\n[%s][%c]\n", (op == 1 ? ("swap") :
		op == 2 ? "push" : op == 4 ? "rotate" : op == 8 ? "rev_rotate" : 0),
				  st == 'a' ? 'a' : st == 'b' ? 'b' : 'x');
		if (op & SWAP)
			st == 'a' ? do_swap(&a) : st == 'b' ? do_swap(&b)
			: (do_swap(&a), do_swap(&b));
		else if (op & PUSH)
			st == 'a' ? do_push(&a, &b, 'a')
			: st == 'b' ? do_push(&a, &b, 'b') : NULL;
		else if (op & ROT)
			st == 'a' ? do_rot(&a) : st == 'b' ? do_rot(&b)
			: (do_rot(&a), do_rot(&b));
		else if (op & REVROT)
			st == 'a' ? do_rev_rot(&a) : st == 'b' ? do_rev_rot(&b)
			: (do_rev_rot(&a), do_rev_rot(&b));
		print_ver(&a, &b);
		ins = ins->next;
	}
	ft_printf("%s\n", (b ? "KO": "OK"));
	free_stacks(&a, &b);
}

//int 			main(int argc, char **argv)
//{
//	int 		*nums;
//	t_list		*ins;
//
//	nums = validate_arguments(argc - 1, argv);
//	if (!(ins = read_instructions()))
//		return (0);
//	apply_instruction(nums, ins, argc - 1);
//
//	free (nums);
//	free_ins(&ins);
//}
