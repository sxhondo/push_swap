#include "push_swap.h"

int 			main(int ac, char **av)
{
	int 		i;
	int 		*nums;
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
	{
		ft_printf("usage: \n");
		return (0);
	}
	if (!(ins = read_instructions()))
		return (0);
	apply_instruction(nums, ins, i);
	free (nums);
	free_ins(&ins);
}