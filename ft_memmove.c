/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 06:58:08 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/08 07:00:04 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;

    if (!dest && !src)
        return (NULL);
    
    d = (unsigned char *)dest;
    s = (const unsigned char *)src;

    // Si el destino está antes que el origen, copiamos hacia adelante
    if (d < s)
    {
        while (n--)
            *d++ = *s++;
    }
    // Si el destino está después que el origen, copiamos hacia atrás
    else if (d > s)
    {
        d += n;
        s += n;
        while (n--)
            *--d = *--s;
    }
    return (dest);
}
