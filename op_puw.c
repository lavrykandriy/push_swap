/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_puw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 05:27:11 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/08 07:50:45 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!a || !b || b->size == 0)
		return ;
	if (a->size)
		ft_memmove(&a->arr[1], &a->arr[0], sizeof(int) * a->size);
	a->arr[0] = b->arr[0];
	a->size++;
	b->size--;
	if (b->size > 0)
		ft_memmove(&b->arr[0], &b->arr[1], sizeof(int) * b->size);
	op_print("pa");
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size == 0)
		return ;
	ft_memmove(&b->arr[1], &b->arr[0], sizeof(int) * b->size);
	b->arr[0] = a->arr[0];
	b->size++;
	a->size--;
	ft_memmove(&a->arr[0], &a->arr[1], sizeof(int) * a->size);
	op_print("pb");
}
