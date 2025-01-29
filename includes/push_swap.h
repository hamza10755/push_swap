/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:39:39 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/30 01:56:47 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int	*numbers;
	int	size;
	int	capacity;
}	t_stack;

t_stack	*create_and_init_stack(int capacity);
void	free_stack(t_stack *stack);

void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	handle_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

int		is_number(char *str);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
void	normalize_array(int *arr, int size);

void	error_exit(void);
void	clean_exit(t_stack *stack_a, t_stack *stack_b);
void	free_split(char **split);

void	sort_temp_array(int *temp, int size);
void	assign_ranks(int *arr, int *temp, int size);

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

#endif