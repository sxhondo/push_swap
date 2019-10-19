#include "push_swap.h"


//13 2 7 19 9
//4 1 18 11 20 17
int 	main(int ac, char **av)
{
	int 	*nums;

	nums = validate_arguments(ac - 1, av);
	sort_stacks(nums, ac - 1);
	free (nums);
}