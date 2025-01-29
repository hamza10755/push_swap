/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:35:38 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/30 01:59:42 by hamzabillah      ###   ########.fr       */
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
	if (stack_a->size <= 5)
		handle_small_stack(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void	normalize_array(int *arr, int size)
{
	int	*temp;
	int	i;

	i = 0;
	temp = (int *)malloc(size * sizeof(int));
	if (!temp)
		return ;
	while (i < size)
	{
		temp[i] = arr[i];
		i++;
	}
	sort_temp_array(temp, size);
	assign_ranks(arr, temp, size);
	free(temp);
}

void	sort_temp_array(int *temp, int size)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (temp[j] > temp[j + 1])
			{
				t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}

void	assign_ranks(int *arr, int *temp, int size)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < size)
	{
		rank = 0;
		j = 0;
		while (j < size)
		{
			if (temp[j] < arr[i])
				rank++;
			j++;
		}
		arr[i] = rank;
		i++;
	}
}
