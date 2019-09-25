#include "push_swap.h"

static int 		check_atoi(const char *str)
{
	int 		sign;
	long 		res;
	unsigned 	i;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? -1 : 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit(1);
		res = res * 10 + (str[i++] - '0');
		if ((sign == 1 && res > INT32_MAX)
			|| (sign == -1 && res - 2 >= INT32_MAX))
			exit (2);
	}
	return ((int)(res * sign));
}

static int 		find_duplicates(const int tab[], int max)
{
	int 		i;
	int 		j;

	i = 0;
	while (i < max)
	{
		j = i + 1;
		while (j < max)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		validate_arguments(int argc, char **argv)
{
	unsigned	i;
	unsigned	j;
	int 		tab[argc];

	i = 1;
	j = 0;
	while (argv[i])
		tab[j++] = check_atoi(argv[i++]);
	if (!(find_duplicates(tab, argc)))
		exit (3);
	return (1);
}

static void		free_instr(t_list **instr)
{
	t_list		*curr;
	t_list		*next;

	curr = *instr;
	while (curr)
	{
		next = curr->next;
		ft_memdel(&curr->content);
		free(curr);
		curr = next;
	}
}

static void		print_instructions(t_list **lst)
{
	t_list		*tmp;
	int 		i;

	i = 1;
	tmp = *lst;
	while (tmp)
	{
		ft_printf("I: [%d] - %s", i++, tmp->content);
		tmp = tmp->next;
	}
}

static char		get_push(char ch)
{
	return ((char)(ch == 'a' ? 'a' : ch == 'b' ? 'b' : 0));
}

static char		get_swap(char ch)
{
	return ((char)(ch == 'a' ? 'a' : ch == 'b' ? 'b' : ch == 's' ? 's' : 0));
}

static char		get_rotate(t_op *op, char ch)
{
	op->stack = ch == 'a' ? 'a' :
				ch == 'b' ? 'b' :
				ch == 'r' ? 'r' : 0u;
}

static int		get_instruction(char *str, t_op *op)
{
	op->operation = 0;
	op->stack = 0;
	while (*str)
	{
		if (*str == 's' && ++str)
		{
			op->operation |= SWAP;
			op->stack = get_swap(*str);
			return (++str ? 0 : 1);
		}
		else if (*str == 'p' && ++str)
		{
			op->operation |= PUSH;
			op->stack = get_push(*str);
		}
		else
			break ;
	}
}

static int		check_instruction(t_list **list)
{
	t_list		*tmp;
	t_op		*op;
	char 		*str;

	op = (t_op*)malloc(sizeof(t_op));
	tmp = *list;
	str = tmp->content;
	while (tmp)
	{
		get_instruction(str, op);
		if (op->stack == 0 || op->operation == 0)
		{
			ft_printf("bad instruction");
			return (0);
		}
		ft_printf("Operation: %u\nStack: %c\n", op->operation, op->stack);
		break;
		tmp = tmp->next;
	}
}

int 			main(int argc, char **argv)
{
	char 		buf[10];
	int 		bytes;
	t_list		*node;
	t_list		*instr;

	if (argc > 1)
		ft_printf("VALID: %d\n", validate_arguments(argc - 1, argv));

	instr = NULL;
	while((bytes = read(0, buf, 5)))
	{
		buf[bytes] = '\0';
		if (bytes <= 2 || bytes > 4
			|| !(node = ft_lstnew(buf, bytes + 1)))
		{
			ft_printf("bad instruction");
			free_instr(&instr);
			return (0);
		}
		ft_lstpushback(&instr, node);
	}
	if (!(check_instruction(&instr)))
		return (0);
	free_instr(&instr);

}
