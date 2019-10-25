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

int 	count_numbers(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			i++;
		else
			put_error(1);
		while (*str && *str++ != ' ')
			;

	}
	return (i);
}

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

void			put_error(int type)
{
	write(2, "Error", 5);
	exit (type);
}