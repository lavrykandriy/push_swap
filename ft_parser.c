/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 23:59:13 by alavryk           #+#    #+#             */
/*   Updated: 2026/10/27 00:31:06 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_single_flag(char *arg, t_config *config);

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_parse_flags(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			ft_check_single_flag(argv[i], config);
			i++;
		}
		else
			break ;
	}
	return (i);
}

static int	*ft_realloc_arr(int *arr, size_t *size_arr, char **str)
{
	int		*res;
	size_t	j;

	res = malloc(sizeof(int) * (*size_arr + ft_lenstrs(str)));
	if (!res)
	{
		free_all(str);
		if (arr)
			free(arr);
		ft_error();
	}
	j = 0;
	while (j < *size_arr)
	{
		res[j] = arr[j];
		j++;
	}
	if (arr)
		free(arr);
	return (res);
}

static int	*ft_process_arg(int *arr, size_t *size_arr, char *arg)
{
	char	**str;
	size_t	j;

	str = ft_split(arg, ' ');
	if (!str)
	{
		if (arr)
			free(arr);
		ft_error();
	}
	arr = ft_realloc_arr(arr, size_arr, str);
	j = 0;
	while (str[j])
		arr[(*size_arr)++] = ft_atol_checker(str[j++]);
	free_all(str);
	return (arr);
}

int	*ft_parser(int argc, char **argv, size_t *size_arr, t_config *config)
{
	int		i;
	int		*arr;
	size_t	s_idx;

	arr = NULL;
	*size_arr = 0;
	s_idx = ft_parse_flags(argc, argv, config);
	if ((int)s_idx >= argc)
		ft_error();
	i = s_idx - 1;
	while (++i < argc)
		arr = ft_process_arg(arr, size_arr, argv[i]);
	if (ft_check_duplicates(arr, *size_arr))
	{
		free(arr);
		ft_error();
	}
	return (arr);
}
