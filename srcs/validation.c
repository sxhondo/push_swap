/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:38:56 by sxhondo           #+#    #+#             */
/*   Updated: 2019/11/05 17:38:58 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_atoi(const char *str, int *tab, int len)
{
	int			sign;
	long		res;
	int			i;

	i = 0;
	res = 0;
	sign = 1;
	if ((*str == '-' || *str == '+') && ++i)
		sign = *str++ == '-' ? -1 : 1;
	if (!*str || !ft_isdigit(*str))
		put_error(1, NULL);
	while (*str && ft_isdigit(*str))
	{
		if (!*str || *str < '0' || *str > '9')
			put_error(1, NULL);
		res = res * 10 + (*str++ - '0');
		i++;
		if ((sign == 1 && res > INT32_MAX)
			|| (sign == -1 && res - 2 >= INT32_MAX))
			put_error(1, NULL);
	}
	if (*str && *str != ' ')
		put_error(1, NULL);
	tab[len] = ((int)res * sign);
	return (i);
}

static int		check_symbols(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '-' && *str != '+' && !ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

static int		find_duplicates(const int tab[], unsigned max)
{
	unsigned	i;
	unsigned	j;

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
	int			i;
	int			j;
	int			tab[argc];
	int			*t;

	j = 0;
	i = 1;
	while (argv[i])
	{
		if (check_symbols(argv[i]))
			put_error(1, NULL);
		check_atoi(argv[i++], tab, j++);
	}
	if (find_duplicates(tab, j))
		put_error(1, NULL);
	t = (int *)malloc(sizeof(int) * j);
	i = -1;
	while (++i < j)
		t[i] = tab[i];
	return (t);
}

int				*validate_string(char *str)
{
	int			i;
	int			j;
	int			*nums;
	int			tab[count_nums(str)];

	i = 0;
	j = count_nums(str);
	if (check_symbols(str))
		put_error(1, NULL);
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		str += check_atoi(str, tab, i++);
	}
	find_duplicates(tab, j) ? put_error(1, NULL) : NULL;
	i = -1;
	nums = (int *)malloc(sizeof(int) * j);
	while (++i < j)
		nums[i] = tab[i];
	return (nums);
}
