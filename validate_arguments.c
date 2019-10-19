/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:37:42 by sxhondo           #+#    #+#             */
/*   Updated: 2019/09/29 14:37:43 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int 		check_atoi(const char *str)
{
	int 		sign;
	long 		res;
	unsigned 	i;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? -1 : 1;
	if (!str[i])
		put_error(1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' || !str[i])
			put_error(1);
		res = res * 10 + (str[i++] - '0');
		if ((sign == 1 && res > INT32_MAX)
			|| (sign == -1 && res - 2 >= INT32_MAX))
			put_error(1);
	}
	return ((int)(res * sign));
}

static int 		find_duplicates(const int tab[], int max)
{
	int 		i;
	int 		j;

	i = 0;
	while (i < max)
	{
		j = i + 1;
		while (j < max)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				*validate_arguments(int argc, char **argv)
{
	unsigned	i;
	unsigned	j;
	int 		tab[argc];
	int			*t;

	i = 1;
	j = 0;
	if (argc < 1)
		put_error(1);
	while (argv[i])
	{
		tab[j++] = check_atoi(argv[i++]);
	}
	if (!(find_duplicates(tab, argc)))
		put_error(3);
	t = (int *)malloc(sizeof(int) * j);
	i = 0;
	while (i < j)
	{
		t[i] = tab[i];
		i++;
	}
	return (t);
}
