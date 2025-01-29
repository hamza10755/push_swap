/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:34:39 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/30 01:55:27 by hamzabillah      ###   ########.fr       */
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

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
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
