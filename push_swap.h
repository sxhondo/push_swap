/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:16:55 by sxhondo           #+#    #+#             */
/*   Updated: 2019/09/24 15:16:55 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

#define SWAP		1u
#define PUSH		2u
#define ROT			4u
#define REVROT		8u

typedef struct		s_op
{
	unsigned int	operation;
	unsigned char	stack;
}					t_op;

/*
** push_swap
 */

void 				sort_stacks(int *nums, unsigned arg_am);


t_list				*fill_a(int *nums, unsigned arg_am);
void				print_ver(t_list **a, t_list **b);
void				print_hor(t_list **a, t_list **b);
void				free_stacks(t_list **a, t_list **b);
/*
** validation
 */

t_list				*read_instructions();
int					*validate_arguments(int argc, char **argv);

/*
** instructions
 */
void				do_swap(t_list **stack);
void				do_push(t_list **a, t_list **b, char in);
void				do_rot(t_list **stack);
void				do_rev_rot(t_list **stack);

/*
** utilites
 */

char				is_push(char ch);
char				is_swap(char ch);
char				is_rotate(char ch);
void				free_ins(t_list **ins);
void				put_error(int type);
#endif
