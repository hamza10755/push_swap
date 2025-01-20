/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:48:40 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/21 00:15:02 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;
	int	i;

	max = 0;
	bits = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->numbers[i] > max)
			max = stack->numbers[i];
		i++;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int	get_median(t_stack *stack)
{
	int	*temp;
	int	i;
	int	median;

	temp = malloc(stack->size * sizeof(int));
	if (!temp)
		return (-1);
	i = -1;
	while (++i < stack->size)
		temp[i] = stack->numbers[i];
	bubble_sort(temp, stack->size);
	median = temp[stack->size / 2];
	free(temp);
	return (median);
}

static void	perform_radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	normalize_array(stack_a->numbers, stack_a->size);
	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		size = stack_a->size;
		j = 0;
		while (j < size)
		{
			if ((stack_a->numbers[0] >> i) & 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 5)
	{
		handle_small_stack(stack_a, stack_b);
		return ;
	}
	perform_radix_sort(stack_a, stack_b);
}
