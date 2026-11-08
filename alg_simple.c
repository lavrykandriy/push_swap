/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 04:14:29 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/08 07:43:57 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_simple(t_stack *a, t_stack *b)
{
	int	idx_start;

	if (!a || !b || a->size < 2)
		return ;
	idx_start = 0;
	while (a->size != 1)
	{
		if (a->arr[0] != idx_start)
				ra(a);
		else
		{
			pb(a, b);
			idx_start++;
		}
	}
	while (b->size)
		pa(a, b);
}
