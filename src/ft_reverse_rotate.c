/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:46:46 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/16 19:47:00 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack_a, int print)
{
	int	temp;
	int	i;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->numbers[stack_a->size - 1];
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->numbers[i] = stack_a->numbers[i - 1];
		i--;
	}
	stack_a->numbers[0] = temp;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b, int print)
{
	int	temp;
	int	i;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->numbers[stack_b->size - 1];
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->numbers[i] = stack_b->numbers[i - 1];
		i--;
	}
	stack_b->numbers[0] = temp;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
