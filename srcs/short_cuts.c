/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cuts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:16:04 by sxhondo           #+#    #+#             */
/*   Updated: 2019/10/30 19:16:05 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_swap(t_list **a, t_list **b, char dst, int verb)
{
	do_swap(dst == 'a' ? a : b);
	if (!verb)
		ft_printf("s%c\n", dst);
	if (verb == 2 || verb == 3)
		ft_printf("exec: {Bred}p%c\n{eoc}", dst);
	if (verb == 1 || verb == 3)
	{
		print_ver(a, b);
		usleep(200000);
		system("clear");
	}
}

void		print_push(t_list **a, t_list **b, char dst, int verb)
{
	do_push(a, b, dst);
	if (verb == 0)
		ft_printf("p%c\n", dst);
	if (verb == 2 || verb == 3)
		ft_printf("exec: {Bred}p%c\n{eoc}", dst);
	if (verb == 1 || verb == 3)
	{
		print_ver(a, b);
		usleep(200000);
		system("clear");
	}
}

void		print_rot(t_list **a, t_list **b, char dst, int verb)
{
	do_rot(dst == 'a' ? a : b);
	if (!verb)
		ft_printf("r%c\n", dst);
	if (verb == 2 || verb == 3)
		ft_printf("exec: {Bred}r%c\n{eoc}", dst);
	if (verb == 1 || verb == 3)
	{
		print_ver(a, b);
		usleep(200000);
		system("clear");
	}
}

void		print_rev_rot(t_list **a, t_list **b, char dst, int verb)
{
	do_rev_rot(dst == 'a' ? a : b);
	if (!verb)
		ft_printf("rr%c\n", dst);
	if (verb == 2 || verb == 3)
		ft_printf("exec: {Bred}rr%c\n{eoc}", dst);
	if (verb == 1 || verb == 3)
	{
		print_ver(a, b);
		usleep(200000);
		system("clear");
	}
}

void		print_rr(t_list **a, t_list **b, int verb)
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