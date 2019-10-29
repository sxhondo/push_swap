#include "push_swap.h"

void				sort_two(t_list **stack)
{
	int 			a;
	int 			b;

	a = *((int *)(*stack)->content);
	b = *((int *)(*stack)->next->content);
	a > b ? do_swap(stack) : NULL;
	ft_printf("sb\n");
}

void				sort_three(t_list **stack)
{
	int a;
	int b;
	int c;

	while (!is_sorted(stack, 0))
	{
		a = *((int *) (*stack)->content);
		b = *((int *) (*stack)->next->content);
		c = *((int *) (*stack)->next->next->content);
		if (a > b && a > c && b < c) /* 3 1 2 */
		{
			do_rot(stack);
			ft_printf("rb\n");
		}
		if (a > b && a > c && b > c)
		{
			do_swap(stack);
			do_rev_rot(stack);
			ft_printf("sb\nrrb\n");
		}
		if (a > b && a < c && b < c)
		{
			do_swap(stack);
			ft_printf("sb\n");
		}
		if (a < b && a > c && b > c)
		{
			do_rev_rot(stack);
			ft_printf("rrb\n");
		}
		if (a < b && a < c && b > c)
		{
			do_swap(stack);
			do_rot(stack);
			ft_printf("sb\nrb\n");
		}
	}
}

int					insertion_sort(t_list **a, t_list **b, int n)
{
	int 			tmp;

	while (n > 3)
	{
		tmp = find_minmax(b, 0);
		rot_index_on_top(b, get_index_for_value(b, tmp), 'b');
		print_push(a, b, 'a');
		print_rot(a, b, 'a');
		n--;
	}
	if (n == 3)
	{
		sort_three(b);
		return (n);
	}
	else if (n == 2)
	{
		sort_two(b);
		return (n);
	}
	else
		return (1);
}
