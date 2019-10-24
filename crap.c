//
//void				small_sort(t_list **stack, int n, char dst)
//{
//	t_list *tmp;
//	int a;
//	int b;
//	int c;
//
//	if (n == 3)
//	{
//		if (dst == 'a')
//			while (!is_sorted(stack, 0))
//			{
//				a = *((int *) (*stack)->content);
//				b = *((int *) (*stack)->next->content);
//				c = *((int *) (*stack)->next->next->content);
//				if (a > b && a > c && b < c) /* 3 1 2 */
//				{
//					do_rot(stack);
//					ft_printf("r%c\n", dst);
//				}
//				if (a > b && a > c && b > c)
//				{
//					do_swap(stack);
//					do_rev_rot(stack);
//					ft_printf("s%c\nrr%c\n", dst, dst);
//				}
//				if (a > b && a < c && b < c)
//				{
//					do_swap(stack);
//					ft_printf("s%c\n", dst);
//				}
//				if (a < b && a > c && b > c)
//				{
//					do_rev_rot(stack);
//					ft_printf("rr%c\n", dst);
//				}
//				if (a < b && a < c && b > c)
//				{
//					do_swap(stack);
//					do_rot(stack);
//					ft_printf("s%c\nr%c\n", dst, dst);
//				}
//			}
//		if (dst == 'b')
//			while (!is_sorted(stack, 1))
//			{
//				a = *((int *) (*stack)->content);
//				b = *((int *) (*stack)->next->content);
//				c = *((int *) (*stack)->next->next->content);
//
//				if (a < b && a < c && b > c)
//				{
//					do_rot(stack);
//					ft_printf("r%c\n", dst);
//				}
//				if (a < b && a < c && b < c)
//				{
//					do_rot(stack);
//					do_swap(stack);
//					ft_printf("r%c\ns%c\n", dst, dst);
//				}
//				if (a > b && a < c && b < c)
//				{
//					do_rev_rot(stack);
//					ft_printf("rr%c\n", dst);
//				}
//				if (a < b && a > c && b > c)
//				{
//					do_swap(stack);
//					ft_printf("s%c\n", dst);
//				}
//				if (a > b && a > c && b < c)
//				{
//					do_rev_rot(stack);
//					do_swap(stack);
//					ft_printf("rr%c\ns%c\n", dst, dst);
//				}
//			}
//	}
//	if (n == 2)
//	{
//		a = *((int *)(*stack)->content);
//		b = *((int *)(*stack)->next->content);
//		a > b ? do_swap(stack) : NULL;
//		ft_printf("s%c\n", dst);
//	}
//}