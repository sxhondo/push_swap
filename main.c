#include "push_swap.h"

//24 19 8 13 82 31 25 17 28 90 61 72 39 16 22 68 11 74 49 10 57 75 44 38 41

//13 2 7 19 9
//4 1 18 11 20 17
int 	main(int ac, char **av)
{
	int 	*nums;

	nums = validate_arguments(ac - 1, av);
	sort_stacks(nums, ac - 1);
	free (nums);
}