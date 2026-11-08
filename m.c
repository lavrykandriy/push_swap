#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*arr;
	size_t	size;
	size_t	i;
	t_config	config;
	t_stack	*a;
	t_stack	*b;

	config.bench = 0;
	config.strat = STRAT_ADAPTIVE;
	if (argc < 2)
		return (0);
	arr = ft_parser(argc, argv, &size, &config);
	a = create_stack(arr, size, size);
	b = create_stack(NULL, 0, size);
	printf("--- PARSER OK ---\n");
	printf("Bench: %d | Strategy: %d | Total elements: %zu\n", 
		config.bench, config.strat, size);
	i = 0;
	while (i < size)
	{
		printf("a.arr[%zu] = %d\n", i, a->arr[i]);
		i++;
	}
	alg_simple(a, b);
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	return (0);
}
