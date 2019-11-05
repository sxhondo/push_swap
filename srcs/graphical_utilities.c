/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:15:19 by sxhondo           #+#    #+#             */
/*   Updated: 2019/10/30 19:15:20 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned				parse_verbose(char *str)
{
	unsigned			v;

	v = 0;
	if (*str == '-')
	{
		str++;
		if (*str && *str == 'v')
		{
			v |= 1u;
			str++;
			if (*str && *str++ == 'c')
				v = 3u;
		}
		if (*str && *str == 'c')
		{
			v |= 2u;
			str++;
			if (*str && *str++ == 'v')
				v = 3u;
		}
	}
	return (v);
}

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
			ft_printf("{cyan}%d{eoc}", *((int *)p_a->content));
			p_a = p_a->next;
		}
		ft_printf("\t");
		if (p_b)
		{
			ft_printf("{magenta}%d{eoc}", *((int *)p_b->content));
			p_b = p_b->next;
		}
		ft_printf("\n");
	}
}

void					print_rr(t_list **a, t_list **b, int verb)
{
	do_rot(a);
	do_rot(b);
	if (!verb)
		ft_printf("rr\n");
	if (verb == 2 || verb == 3)
		ft_printf("exec: {Bred}rr\n{eoc}");
	if (verb == 1 || verb == 3)
	{
		print_ver(a, b);
		usleep(200000);
		system("clear");
	}
}

void					print_rrr(t_list **a, t_list **b, int verb)
{
	do_rev_rot(a);
	do_rev_rot(b);
	if (!verb)
		ft_printf("rrr\n");
	if (verb == 2 || verb == 3)
		ft_printf("exec: {Bred}rrr\n{eoc}");
	if (verb == 1 || verb == 3)
	{
		print_ver(a, b);
		usleep(200000);
		system("clear");
	}
}
