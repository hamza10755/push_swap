/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:39:44 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/16 22:32:48 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a))
        return;

    if (stack_a->size <= 5)
        hybrid_sort(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}

void restore_stack(t_stack *stack, int min)
{
    int i;
    
    i = 0;
    while (i < stack->size)
    {
        stack->numbers[i] += min;
        i++;
    }
}
void partition_and_sort(t_stack *stack_a, t_stack *stack_b)
{
    int pivot;
    int count;
    int size;
    int i;

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
