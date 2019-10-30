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
** push_swap.c
 */

void 				sort_stacks(int *nums, unsigned arg_am);
t_list				*fill_a(int *nums, unsigned arg_am);

/*
** small_sort.c
 */
void				sort_two(t_list **stack);
void				sort_three(t_list **stack);
int					insertion_sort(t_list **a, t_list **b, int n);

/*
** ps_utilities1.c
 */
int 				is_sorted(t_list **stack, int mode);
int 				get_index_for_value(t_list **stack, int value);
int 				get_value_for_index(t_list **stack, int index);
int 				take_int_delete_node(t_list **tab);

/*
** graphical_utilities.c
 */
void				print_push(t_list **a, t_list **b, char dst);
void				print_rot(t_list **a, t_list **b, char dst);

/*
** find_med_value.c
 */
int 				find_medvalue(t_list **stack);


int 				find_less(t_list **stack, int min);
int 				find_greater(t_list **stack, int val);

int					rot_index_on_top(t_list **stack, int index, char dst);
int 				find_minmax(t_list **stack, int mode);



void				print_ver(t_list **a, t_list **b);
void				print_hor(t_list **a, t_list **b);
void				free_stacks(t_list **a, t_list **b);

/*
** validatation.c
 */

int					*validate_array(int argc, char **argv);
int 				*validate_string(char *str);



void					apply_instruction(int *nums, t_list *ins,
										  unsigned arg_am);
t_list				*read_instructions();

/*
** parse_arguments.c
 */
char 				**parse_array(const char *str);

/*
** instructions
 */
void				do_swap(t_list **stack);
void				do_push(t_list **a, t_list **b, char in);
void				do_rot(t_list **stack);
void				do_rev_rot(t_list **stack);

/*
** validation_utilites.c
 */

char				is_push(char ch);
char				is_swap(char ch);
char				is_rotate(char ch);
void				free_ins(t_list **ins);
void				put_error(int type, t_list **stack);
int 				count_nums(char *str);
#endif
