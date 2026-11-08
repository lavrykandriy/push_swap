/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 23:11:09 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/08 01:27:47 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*value_to_index(int *arr, int *srt, size_t size)
{
	size_t	i;
	size_t	j;
	int		*new;

	new = malloc(size * sizeof(int));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (arr[i] == srt[j])
			{
				new[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (new);
}

int	*sorted_arr(int	*arr, size_t	size)
{
	int	i;
	int	j;
	int	*srt;

	srt = (int *)malloc((int)size * sizeof (int));
	if (!srt)
		return (NULL);
	i = -1;
	while (++i < (int)size)
		srt[i] = arr[i];
	i = -1;
	while (++i < (int)size - 1)
	{
		j = i;
		while (++j < (int)size)
		{
			if (srt[i] > srt[j])
			{
				srt[i] = srt[i] ^ srt[j];
				srt[j] = srt[i] ^ srt[j];
				srt[i] = srt[i] ^ srt[j];
			}
		}
	}
	return (srt);
}

t_stack	*create_stack(int *arr, size_t size, size_t capacity)
{
	size_t	i;
	size_t	j;
	int		*srt;
	int		*new_vl_idx;
	t_stack	*stack;

	if (arr && size)
	{
		srt = sorted_arr(arr, size);
		new_vl_idx = value_to_index(arr, srt, size);
		free(arr);
		free(srt);
		stack->arr = new_vl_idx;
	}
	else
		stack->arr = malloc(capacity * sizeof(int));
	stack->size = size;
	stack->capacity = capacity;
	return (stack);
}
