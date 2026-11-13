/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_alenya.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 01:33:07 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/13 02:02:51 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_above_median(int idx, t_stack *stack)
{	
	int	len;
	int	i;

	len = stack->size;
	i = 0;
	while (i < len)
	{
		if (stack->arr[i] == idx)
			return (i < len / 2);
		i++;
	}
	return (0);
}

void    alg_alenya(t_stack *a, t_stack *b)
{
        int     idx_start;

        if (!a || !b || a->size < 2)
                return ;
        idx_start = 0;
        while (a->size != 1)
        {
                if (a->arr[0] == idx_start)
		{
                                pb(a, b);
				idx_start++;
		}		
                while (a->arr[0] != idx_start && is_above_median(idx_start, a))
			ra(a);
		while (a->arr[0] != idx_start && !is_above_median(idx_start, a))
			rra(a);
	}
        while (b->size)
                pa(a, b);
}
