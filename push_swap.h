/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:16:55 by sxhondo           #+#    #+#             */
/*   Updated: 2019/11/06 20:16:21 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# define SWAP		1u
# define PUSH		2u
# define ROT		4u
# define REVROT		8u

typedef struct		s_op
{
	unsigned int	operation;
	unsigned char	stack;
}					t_op;

/*
** push_swap.c
*/

void				sort_stacks(int *nums, unsigned arg_am, int verb);

/*
** read_parse_instructions.c
*/

t_list				*read_instructions(void);

/*
** validatation.c
*/

int					*validate_array(int argc, char **argv);
int					*validate_string(char *str);

/*
** validation_utilites.c
*/

char				is_push(char ch);
char				is_swap(char ch);
char				is_rotate(char ch);
void				free_ins(t_list **ins);
int					count_nums(char *str);

/*
** apply_instruction.c
*/

t_list				*fill_a(int *nums, unsigned arg_am);
void				free_stacks(t_list **a, t_list **b);
void				apply_instruction(int *nums, t_list *ins, unsigned arg_am);

/*
** instructions
*/

void				do_swap(t_list **stack);
void				do_push(t_list **a, t_list **b, char in);
void				do_rot(t_list **stack);
void				do_rev_rot(t_list **stack);

/*
** small_sort.c
*/

void				sort_small_stack(t_list **a, t_list **b, int verb);
void				sort_two(t_list **a, t_list **b, char dst, int verb);
void				insertion_sort(t_list **a, t_list **b, int verb);

/*
** ps_utilities1.c
*/

int					get_index_for_value(t_list **stack, int value);
int					find_less(t_list **stack, int min);
int					find_greater(t_list **stack, int val);
int					find_minmax(t_list **stack, int mode);
int					is_sorted(t_list **stack, int mode);

/*
** ps_utilities2.c
*/

void				put_error(int type, t_list **stack);
int					take_int_delete_node(t_list **tab);
int					rot_index_on_top(t_list **stack, int index,
										int verb, char dst);
/*
** ps_utilities2.c
*/

void				optimised_rot(t_list **a, t_list **b, int rra, int verb);

/*
** short_cuts.c
*/

void				print_push(t_list **a, t_list **b, char dst, int verb);
void				print_rot(t_list **a, t_list **b, char dst, int verb);
void				print_rev_rot(t_list **a, t_list **b, char dst, int verb);
void				print_swap(t_list **a, t_list **b, char dst, int verb);

/*
** graphical_utilites.c
*/

unsigned			parse_verbose(char *str);
void				print_hor(t_list **a, t_list **b);
void				print_ver(t_list **a, t_list **b);
void				print_rr(t_list **a, t_list **b, int verb);
void				print_rrr(t_list **a, t_list **b, int verb);

/*
** find_med_value.c
*/

int					find_medvalue(t_list **stack, int max_len);

#endif
