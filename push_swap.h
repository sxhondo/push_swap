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
** validation
 */
t_list				*read_validate(int argc, char **argv);

/*
** utilites
 */
char				is_push(char ch);
char				is_swap(char ch);
char				is_rotate(char ch);
void				free_ins(t_list **ins);
void				print_ins(t_list **lst);
#endif
