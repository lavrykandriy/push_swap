/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 23:58:39 by alavryk           #+#    #+#             */
/*   Updated: 2026/10/27 00:35:13 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_lenstrs(char **str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_check_single_flag(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		config->bench = 1;
	else if (ft_strncmp(arg, "--simple", 9) == 0)
		config->strat = STRAT_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		config->strat = STRAT_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		config->strat = STRAT_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		config->strat = STRAT_ADAPTIVE;
	else
		ft_error();
}

static void	ft_parse_digits(char *str, long *num, int sign, int i)
{
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		*num = *num * 10 + (str[i] - '0');
		if (*num > 2147483647L + (sign == -1))
			ft_error();
		i++;
	}
}

int	ft_atol_checker(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (!str || !str[0])
		ft_error();
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		ft_error();
	ft_parse_digits(str, &num, sign, i);
	return ((int)(num * sign));
}

int	ft_check_duplicates(int *arr, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
