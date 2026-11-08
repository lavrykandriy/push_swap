/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 06:25:02 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/08 07:39:27 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	static int	cnt = 0;
	int	tmp;

	if (!a || a->size < 2) 
		return ;
	tmp = a->arr[0];
	ft_memmove(&a->arr[0], &a->arr[1], sizeof(int) * (a->size - 1));
	a->arr[a->size - 1] = tmp;
	op_print("ra");
	if (cnt++ == 35)
		exit(1);
}

void	rb(t_stack *a)
{
	int	tmp;

	if (!a || a->size < 2) 
		return ;
	tmp = a->arr[0];
	ft_memmove(&a->arr[0], &a->arr[1], sizeof(int) * (a->size - 1));
	a->arr[a->size - 1] = tmp;
	op_print("rb");
}
