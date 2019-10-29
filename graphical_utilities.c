#include "push_swap.h"

void		print_push(t_list **a, t_list **b, char dst)
{
	do_push(a, b, dst);
	ft_printf("p%c\n", dst);
}

void		print_rot(t_list **a, t_list **b, char dst)
{
	do_rot(dst == 'a' ? a : b);
	ft_printf("r%c\n", dst);
}

void					print_hor(t_list **a, t_list **b)
{
	t_list				*p_a;
	t_list				*p_b;

	p_a = a ? *a : NULL;
	p_b = b ? *b : NULL;

	ft_printf("A: ");
	while (p_a)
	{
		ft_printf("%3d ", *((int*)p_a->content));
		p_a = p_a->next;
	}
	ft_printf("\nB: ");
	while (p_b)
	{
		ft_printf("%3d ", *((int*)p_b->content));
		p_b = p_b->next;
	}
	ft_printf("\n\n");
}

void					print_ver(t_list **a, t_list **b)
{
	t_list				*p_a;
	t_list				*p_b;

	p_a = a ? *a : NULL;
	p_b = b ? *b : NULL;
	ft_printf("\na\tb\n---------\n");
	while (p_a || p_b)
	{
		if (p_a)
		{
			ft_printf("%d", *((int *)p_a->content));
			p_a = p_a->next;
		}
		ft_printf("\t");
		if (p_b)
		{
			ft_printf("%d", *((int *)p_b->content));
			p_b = p_b->next;
		}
		ft_printf("\n");
	}
}
