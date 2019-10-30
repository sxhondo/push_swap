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

static int 		check_atoi(const char *str, int mode)
{
	int 		sign;
	long 		res;
	unsigned 	i;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? -1 : 1;
	if ((mode && !str[i]) || (mode && !ft_isdigit(str[i])))
		put_error(1, NULL);
	while (str[i] && ft_isdigit(str[i]))
	{
		if (str[i] < '0' || str[i] > '9' || !str[i])
			put_error(1, NULL);
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > INT32_MAX)
			|| (sign == -1 && res - 2 >= INT32_MAX))
			put_error(1, NULL);
		i++;
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int				*validate_array(int argc, char **argv)
{
	unsigned	i;
	unsigned	j;
	int 		tab[argc];
	int			*t;

	j = 0;
	i = 1;
	while (argv[i])
		tab[j++] = check_atoi(argv[i++], 0);
	if (find_duplicates(tab, j))
		put_error(1, NULL);
	t = (int *)malloc(sizeof(int) * j);
	i = 0;
	while (i < j)
	{
		t[i] = tab[i];
		i++;
	}
	return (t);
}

int 			*validate_string(char *str)
{
	int 		i;
	int 		j;
	int 		*nums;
	int 		tab[count_nums(str)];

	i = 0;
	j = count_nums(str);
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		if (!*str)
			break;
		tab[i++] = check_atoi(str, 1);
		str += ft_nblen(tab[i - 1]);
	}
	if (find_duplicates(tab, j))
		put_error(1, NULL);
	i = 0;
	nums = (int *)malloc(sizeof(int) * j);
	while (i < j)
	{
		nums[i] = tab[i];
		i++;
	}
	return (nums);
}
