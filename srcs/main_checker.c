/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:52:38 by sxhondo           #+#    #+#             */
/*   Updated: 2019/11/05 17:52:39 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int ac, char **av)
{
	int			i;
	int			*nums;
	t_list		*ins;

	if (ac == 2)
	{
		i = count_nums(av[1]);
		nums = validate_string(av[1]);
	}
	else if (ac >= 3)
	{
		i = ac - 1;
		nums = validate_array(i, av);
	}
	else
		return (0);
	ins = read_instructions();
	apply_instruction(nums, ins, i);
	free(nums);
	free_ins(&ins);
}
