//
//#include "push_swap.h"
//
////algorithm quicksort(A, low, high) is
////if low < high then
////p := partition(A, low, high)
////quicksort(A, low, p - 1)
////quicksort(A, p + 1, high)
//
//
////algorithm partition(A, low, high) is
////		pivot := A[(low + high) / 2]
////i := low - 1
////j := high + 1
////loop forever
////do
////i := i + 1
////while A[i] < pivot
////
////do
////j := j - 1
////while A[j] > pivot
////
////if i >= j then
////return j
////
////		swap A[i] with A[j]
//
//
//
//void	print(int *tab, unsigned u)
//{
//	int 	i = 0;
//
//	while (i <= u)
//	{
//		ft_printf("%d\t", tab[i]);
//		i++;
//	}
//	ft_printf("\n");
//}
//
//int 			partition(int *tab, unsigned low, unsigned high)
//{
//	int 		pivot = tab[(low + high) / 2];
//	int			i = low - 1;
//	int 		j = high + 1;
//	int 		tmp;
//
//	while (1)
//	{
//		while (tab[++i] < pivot)
//			;
//		while (tab[--j] > pivot)
//			;
//		if (i >= j)
//		{
//			print(tab, high);
//			return (j);
//		}
//		tmp = tab[i];
//		tab[i] = tab[j];
//		tab[j] = tmp;
//	}
//}
//
//void			quick_sort(int *tab, unsigned low, unsigned high)
//{
//	int 		p;
//
//	if (low < high)
//	{
//		p = partition(tab, low, high);
//		quick_sort(tab, low, p - 1);
//		quick_sort(tab, p + 1, high);
//	}
//}
//
//void 			sort_stacks(int *nums, unsigned arg_am)
//{
//	t_list		*a;
//	t_list		*b;
//	int 		tmp;
//	int 		llen;
//
//	b = NULL;
//	a = fill_a(nums, arg_am);
//	quick_sort(nums, 0, arg_am - 1);
//}
