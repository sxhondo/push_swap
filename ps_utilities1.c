#include "push_swap.h"

int 			get_value_for_index(t_list **stack, int index)
{
	t_list		*tmp;

	tmp = *stack;
	while (index)
	{
		tmp = tmp->next;
		index--;
	}
	return (*((int *)tmp->content));
}

int 			get_index_for_value(t_list **stack, int value)
{
	int 		i;
	t_list		*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) == value)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int 			find_less(t_list **stack, int min)
{
	t_list		*tmp;
	int 		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) < min)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int 			find_greater(t_list **stack, int val)
{
	t_list		*tmp;
	int 		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) > val)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}


int 			find_minmax(t_list **stack, int mode)
{
	t_list		*i;
	t_list		*j;
	int 		curr;

	i = *stack;
	while (i)
	{
		curr = *((int *)i->content);
		j = *stack;
		while (!mode && j && *((int *)j->content) >= curr)
			j = j->next;
		while (mode && j && *((int *)j->content) <= curr)
			j = j->next;
		if (!j)
			return (curr);
		i = i->next;
	}
	return (-1);
}

int 			find_less_greater(t_list **stack, int min, int max)
{
	t_list		*tmp;
	int 		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (*((int *)tmp->content) < min && *((int *)tmp->content) > max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int					rot_index_on_top(t_list **stack, int index, char dst)
{
	int 		llen;

	llen = ft_lstlen(stack);
	if (index < 0)
		return (0);
	if (index <= llen / 2)
	{
		while (index-- > 0)
		{
			do_rot(stack);
			ft_printf("r%c\n", dst);
		}
	}
	else
	{
		while (index++ <= llen - 1)
		{
			do_rev_rot(stack);
			ft_printf("rr%c\n", dst);
		}
	}
	return (1);
}

int 			is_sorted(t_list **stack, int mode)
{
	t_list		*tmp;

	tmp = *stack;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if (!mode && *((int *)tmp->content) < *((int *)tmp->next->content))
			tmp = tmp->next;
		else if (mode && *((int *)tmp->content) > *((int *)tmp->next->content))
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}


int 			take_int_delete_node(t_list **tab)
{
	int 			j;
	t_list			*next;
	t_list			*curr;

	curr = *tab;
	next = curr->next;
	j = *((int *)curr->content);
	ft_memdel(&curr->content);
	free(curr);
	*tab = next;
	return (j);
}