/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 23:53:03 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/08 07:13:07 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_config
{
	t_strategy	strat;
	int			bench;
}	t_config;

typedef struct s_stack
{
	int			*arr;
	size_t		size;
	size_t		capacity;
}	t_stack;
// --stack.c ---
t_stack	*create_stack(int *arr, size_t size, size_t capacity);

// --- utils.c ---
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			**free_all(char **arr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// --- ft_split.c ---
char				**ft_split(char const *s, char c);

// --- op_print.c ---
void    op_print(char *str);

// --- puw.c ---
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// --- op_rotate.c ---
void	ra(t_stack *a);
void	rb(t_stack *a);

// --- alg_simple.c ---
void	alg_simple(t_stack *a, t_stack *b);

// --- ft_memmove.c ---
void	*ft_memmove(void *dest, const void *src, size_t n);

// --- parser.c & parser_utils.c ---
void		ft_error(void);
size_t		ft_lenstrs(char **str);
void		ft_check_single_flag(char *arg, t_config *config);
int			ft_atol_checker(char *str);
int			ft_check_duplicates(int *arr, size_t size);
int			*ft_parser(int argc, char **argv,
				size_t *size_arr, t_config *config);

#endif
