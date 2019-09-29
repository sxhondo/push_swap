#include "push_swap.h"

int 			main(int argc, char **argv)
{
	int 		*nums;
	t_list		*ins;

	nums = validate_arguments(argc - 1, argv);
//	if (!(ins = read_instructions()))
//		return (0);
//	print_ins(&ins);
	ft_printf("\n-------\n");
//	int i = 0;
//	while (i < argc - 1)
//		ft_printf("ARGS\t\t[%d]\n", nums[i++]);
	apply_instruction(nums, NULL, argc - 1);

	free (nums);
//	free_ins(&ins);

}