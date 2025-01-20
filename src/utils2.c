/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:39:44 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/21 00:25:38 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_and_init_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->numbers = (int *)malloc(sizeof(int) * capacity);
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	ft_bzero(stack->numbers, sizeof(int) * capacity);
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size <= 5)
		hybrid_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void	restore_stack(t_stack *stack, int min)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		stack->numbers[i] += min;
		i++;
	}
}

void	partition_and_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	int	count;
	int	size;
	int	i;

	size = stack_a->size;
	count = 0;
	pivot = get_median(stack_a);
	i = 0;
	while (i < size)
	{
		if (stack_a->numbers[0] <= pivot)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a, 1);
		i++;
	}
	hybrid_sort(stack_a, stack_b);
	while (count--)
		pa(stack_a, stack_b);
}

void	normalize_stack(t_stack *stack, int *min)
{
	int	i;

	*min = stack->numbers[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->numbers[i] < *min)
			*min = stack->numbers[i];
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		stack->numbers[i] -= *min;
		i++;
	}
}
