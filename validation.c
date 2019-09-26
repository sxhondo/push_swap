/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:54:33 by sxhondo           #+#    #+#             */
/*   Updated: 2019/09/26 19:54:33 by sxhondo          ###   ########.fr       */
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
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit(1);
		res = res * 10 + (str[i++] - '0');
		if ((sign == 1 && res > INT32_MAX)
			|| (sign == -1 && res - 2 >= INT32_MAX))
			exit (2);
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

static int		validate_arguments(int argc, char **argv)
{
	unsigned	i;
	unsigned	j;
	int 		tab[argc];

	i = 1;
	j = 0;
	while (argv[i])
		tab[j++] = check_atoi(argv[i++]);
	if (!(find_duplicates(tab, argc)))
		exit (3);
	return (1);
}

static void		get_instruction(char *str, t_op *op, int bytes)
{
	while (*str)
	{
		if (*str == 's' && ++str)
		{
			op->operation |= SWAP;
			op->stack = is_swap(*str++);
		}
		else if (*str == 'p' && ++str)
		{
			op->operation |= PUSH;
			op->stack = is_push(*str);
		}
		else if (*str == 'r' && ++str)
		{
			op->operation |= (bytes == 3) ? ROT : REVROT;
			op->stack = op->operation & ROT ?
						is_rotate(*str) : is_rotate(*++str);
			str++;
		}
		else
			break ;
	}
}

static t_op		*parse_instruction(char *buf, int bytes)
{
	t_op		*ops;

	if (!(ops = (t_op*)malloc(sizeof(t_op))))
		return (NULL);
	ops->operation = 0;
	ops->stack = 0;
	get_instruction(buf, ops, bytes);
	if (!ops->stack || !ops->operation)
	{
		free(ops);
		return (NULL);
	}
	return (ops);
}

t_list			*read_validate(int argc, char **argv)
{
	char 		buf[10];
	int 		bytes;
	t_op		*ops;
	t_list		*node;
	t_list		*instr;

	if (argc > 1)
		ft_printf("VALID: %d\n", validate_arguments(argc - 1, argv));
	instr = NULL;
	while((bytes = read(0, buf, 5)))
	{
		buf[bytes] = '\0';
		if (bytes <= 2 || bytes > 4 || !(ops = parse_instruction(buf, bytes)))
		{
			ft_printf("bad instruction");
			free_ins(&instr);
			return (NULL);
		}
		if (!(node = ft_lstnew(ops, sizeof(ops))))
			return (NULL);
		free (ops);
		ft_lstpushback(&instr, node);
	}
	return (instr);
}