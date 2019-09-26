/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:56:54 by sxhondo           #+#    #+#             */
/*   Updated: 2019/09/26 19:56:55 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			is_push(char ch)
{
	return ((char)(ch == 'a' ? 'a' : ch == 'b' ? 'b' : 0));
}

char			is_swap(char ch)
{
	return ((char)(ch == 'a' ? 'a' : ch == 'b' ? 'b' : ch == 's' ? 's' : 0));
}

char			is_rotate(char ch)
{
	return ((char)(ch == 'a' ? 'a' : ch == 'b' ? 'b' : ch == 'r' ? 'r' : 0));
}

void			free_ins(t_list **ins)
{
	t_list		*curr;
	t_list		*next;

	curr = *ins;
	while (curr)
	{
		next = curr->next;
		free(curr->content);
		free(curr);
		curr = next;
	}
}

void			print_ins(t_list **lst)
{
	t_list		*tmp;
	int 		i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		ft_printf("I: [%d]\nOPERATION: %d\nSTACK: %c\n", i++,
				  ((t_op *)tmp->content)->operation, ((t_op *)tmp->content)->stack);
		tmp = tmp->next;
	}
}
