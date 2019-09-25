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
#define RROT		8u

typedef struct		s_op
{
	unsigned int	operation;
	unsigned char	stack;
}					t_op;

#endif
