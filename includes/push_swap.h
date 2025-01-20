/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:39:39 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/17 18:53:27 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*numbers;
	int	size;
	int	capacity;
}		t_stack;

void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);

void	radix_sort(t_stack *stack_a, t_stack *stack_b);

void	error_exit(void);
void	clean_exit(t_stack *stack_a, t_stack *stack_b);

void	free_stack(t_stack *stack);
int		is_number(char *str);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
void	normalize_array(int *arr, int size);
void	restore_stack(t_stack *stack, int min);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	hybrid_sort(t_stack *stack_a, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
int		get_median(t_stack *stack);
void	partition_and_sort(t_stack *stack_a, t_stack *stack_b);
void	handle_small_stack(t_stack *stack_a, t_stack *stack_b);
void	free_split(char **split);
t_stack	*create_and_init_stack(int capacity);

#endif