#include "push_swap.h"

int 	main(int ac, char **av)
{
	int 	*nums;

	nums = validate_arguments(ac - 1, av);
	sort_stacks(nums, ac - 1);

	free (nums);
}