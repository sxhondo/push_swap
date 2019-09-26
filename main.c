#include "push_swap.h"

int 			main(int argc, char **argv)
{
	t_list		*ins;

	if (!(ins = read_validate(argc, argv)))
		return (0);
	print_ins(&ins);
	free_ins(&ins);

}