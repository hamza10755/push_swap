/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:38:44 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/16 22:11:44 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_temp_array(int *temp, int size)
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

static void	assign_ranks(int *arr, int *temp, int size)
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

void	handle_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2 && stack_a->numbers[0] > stack_a->numbers[1])
		sa(stack_a, 1);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}

void	hybrid_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 5)
	{
		handle_small_stack(stack_a, stack_b);
		return ;
	}
	partition_and_sort(stack_a, stack_b);
}
