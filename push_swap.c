#include "push_swap.h"

int				parallel_pre_sort(t_list **a, t_list **b,
									 int n, char stack)
{
	int k_val;
	int tmp;
	int i_a, i_b;

	k_val = stack == 'a' ? find_medvalue(a, ft_lstlen(a)) : find_minmax(b, 1);
	tmp = ft_lstlen(a) > ft_lstlen(b) ? ft_lstlen(a) : ft_lstlen(b);
	while (tmp--)
	{
		i_a = find_less(a, k_val);
		i_b = find_greater(b, k_val);
		if (i_a == -1 && i_b == -1)
			break;
		smart_rot(a, b, i_a, i_b);
		if (i_a > -1)
		{
			do_push(a, b, 'b');
			do_rot(b);
			ft_printf("pb\nrb\n");
		}
		if (i_b > -1)
		{
			do_push(a, b, 'a');
			ft_printf("pa\n");
		}
	}
	return (-1);
}

void			quick_sort(t_list **a, t_list **b, int med, t_list **tab)
{
	t_list		*s;
	int 		j;
	int 		i;

	j = 0;
	if (ft_lstlen(b) == 3)
	{
		small_sort(b, 3, 'a');

		return ;
	}
	if (ft_lstlen(b) == 2)
		return (sort_two(b, 'b'));
	j = 0;
	while ((i = find_greater(b, med)) >= 0)
	{
		rot_index_on_top(b, i, 'b');
		do_push(a, b, 'a');
		ft_printf("pb\n");
		j++;
	}
	if (!(s = ft_lstnew(&j, j)))
		return;
	ft_lstadd(tab, s);
	quick_sort(a, b, find_medvalue(b, ft_lstlen(b)), tab);
}

void			push_larger_half(t_list **a, t_list **b)
{
	int 		min;

	min = find_minmax(a, 0);
	int head = *((int *)(*a)->content);
	while (head != min)
	{
		do_push(a, b, 'b');
		head = *((int *)(*a)->content);
	}
}

void			back_track(t_list **a, t_list **b)
{
	int 	i;
	int 	j;
	int 	med;
	t_list	*next;
	t_list	*tab = NULL;

	while (1)
	{
		med = find_medvalue(b, ft_lstlen(b));
		if (med == -1)
			return;
		quick_sort(a, b, med, &tab);
		i = ft_lstlen(b);
		while (i--)
		{
			do_push(a, b, 'a');
			do_rot(a);
		}
		if (!tab)
			break;
//		for (p = tab; p; p = p->next)
//			ft_printf("{Bred} %10d {eoc}\n", *((int *) p->content));
		j = *((int *) (*tab).content);
		next = (*tab).next;
		free(tab);
		tab = next;
		while (j--)
			do_push(a, b, 'b');
	}

	push_larger_half(a, b);
	back_track(a, b);
}

void 			sort_stacks(int *nums, unsigned arg_am)
{
	t_list		*a;
	t_list		*b;
	int 		i;

	b = NULL;
	a = fill_a(nums, arg_am);
	parallel_pre_sort(&a, &b, ft_lstlen(&a), 'a');
	back_track(&a, &b);
	print_hor(&a, &b);
	free_ins(&a);

}