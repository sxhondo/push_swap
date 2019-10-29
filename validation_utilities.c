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

int 			count_nums(char *str)
{
	int 		i;
	int 		q;

	i = 0;
	q = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			q++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		while (str[i] && !ft_isdigit(str[i]))
			i++;
	}
	return (q);
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

void			put_error(int type, t_list **stack)
{
	if (type == 3)
		free_ins(stack);
	write(2, "Error", 5);
	exit (type);
}