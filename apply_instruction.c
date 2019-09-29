
#include "push_swap.h"

void			do_swap(t_list **stack)
{
	t_list		*tmp;

	if (ft_lstlen(stack) < 1)
	{
		ft_printf("\nnot enough elements on stack\n");
		return;
	}
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
}

void			do_push(t_list **a, t_list **b, char stack)
{
	t_list		*ptr;
	t_list		*next;

	if (stack == 'a')
	{
		ptr = *b;
		if (!ptr || ft_lstlen(&ptr) == 0)
		{
			ft_printf("b is empty\n");
			return;
		}
		next = ptr->next; //save next elem in (B)
		ptr->next = *a; //P_b->next points to head (A)
		*a = ptr; //head (A) moved to new beginning
		*b = next; //head (B) moved to next elem
	}
	else if (stack == 'b')
	{
		ptr = *a;
		if (!ptr || ft_lstlen(&ptr) == 0)
		{
			ft_printf("a is empty\n");
			return;
		}
		next = ptr->next;
		ptr->next = *b;
		*b = ptr;
		*a = next;
	}
}

void			do_rot(t_list **stack)
{
	t_list		*ptr;
	t_list		*next;

	if (ft_lstlen(stack) == 1)
		return;
	ptr = *stack;
	next = ptr->next; // save next
	ptr->next = NULL; // first elem points to NULL
	*stack = next; // head now on saved (second) elem
	while ((*stack)->next) // iter to the last elem
		*stack = (*stack)->next;
	(*stack)->next = ptr;
	*stack = next;
}

void			do_rev_rot(t_list **stack)
{
	t_list		*ptr;
	t_list		*save;

	if (ft_lstlen(stack) == 1)
		return;
	ptr = *stack;
	while (ptr->next->next)
		ptr = ptr->next;
	save = ptr->next;
	ptr->next = NULL;
	save->next = *stack;
	*stack = save;
}

void			apply_instruction(int *nums, t_list *ins, int arg_am)
{
	//*((int *)node->content)
	t_list		*a;
	t_list		*b;
	t_list		*node;
	int 		i, t;

	i = 0;
	a = NULL;
	b = NULL;

	while (i < arg_am)
	{
		if (!(node = ft_lstnew(&nums[i], sizeof(int))))
			return;
		ft_lstpushback(&a, node);
		i++;
	}

	for (t = 4, i = 0; i < arg_am; i++, t++)
		ft_lstpushback(&b, ft_lstnew(&t, sizeof(int)));

//	do_swap(&a);
//	do_push(&a, &b, 'b');
//	do_rot(&b);
//	do_rev_rot(&b);


	while (a)
	{
		ft_printf("A: %d\n", *((int *)a->content));
		a = a->next;
	}
	ft_printf("\n---\n");
	while (b)
	{
		ft_printf("B: %d\n", *((int *)b->content));
		b = b->next;
	}

}