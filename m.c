#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*arr;
	size_t	size;
	size_t	i;
	t_config	config;

	config.bench = 0;
	config.strat = STRAT_ADAPTIVE;
	if (argc < 2)
		return (0);
	arr = ft_parser(argc, argv, &size, &config);
	printf("--- PARSER OK ---\n");
	printf("Bench: %d | Strategy: %d | Total elements: %zu\n", 
		config.bench, config.strat, size);
	i = 0;
	while (i < size)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
