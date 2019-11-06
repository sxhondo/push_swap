/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:52:34 by sxhondo           #+#    #+#             */
/*   Updated: 2019/11/05 17:52:35 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int ac, char **av)
{
	int			v;
	int			i;
	int			*nums;

	if (ac == 2)
	{
		i = 0;
		if ((v = (int)parse_verbose(av[1])))
		{
			while (av[1][i] && (av[1][i] == '-' || av[1][i] == 'v' ||
								av[1][i] == 'c'))
				av[1]++;
		}
		i = count_nums(av[1]);
		nums = validate_string(av[1]);
	}
	else if (ac >= 3 && (i = ac - 1))
	{
		((v = (int)parse_verbose(av[1])) && --i) ? av++ : NULL;
		nums = validate_array(i, av);
	}
	else
		return (0);
	sort_stacks(nums, i, (int)v);
	free(nums);
}
