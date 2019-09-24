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

int				validate_arguments(int argc, char **argv)
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

int 	main(int argc, char **argv)
{
	int 	bytes;
	char 	buf[42];

	if (argc == 1)
		return (0);
	else if (argc > 1)
		validate_arguments(argc - 1, argv);
	while ((bytes = read(0, buf, 4)))
	{
		buf[bytes] = '\0';
		ft_printf("%s", buf);
	}
}
