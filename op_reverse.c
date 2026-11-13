/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 02:03:58 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/13 02:19:37 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void    rra(t_stack *a)
{
        static int      cnt = 0;
        int     tmp;

        if (!a || a->size < 2)
                return ;
        tmp = a->arr[a->size - 1];
        ft_memmove(&a->arr[1], &a->arr[0], sizeof(int) * (a->size - 1));
        a->arr[0] = tmp;
        op_print("rra");
        if (cnt++ == 35)
                exit(1);
}

void    rrb(t_stack *a)
{
        int     tmp;

        if (!a || a->size < 2)
                return ;
        tmp = a->arr[a->size - 1];
        ft_memmove(&a->arr[1], &a->arr[0], sizeof(int) * (a->size - 1));
        a->arr[0] = tmp;
        op_print("rrb");
}
