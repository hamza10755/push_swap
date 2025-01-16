/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:48:40 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/16 22:26:09 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
static int get_max_bits(t_stack *stack)
{
    int max;
    int bits;
    int i;
    
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
    return bits;
}


int get_median(t_stack *stack)
{
    int *temp;
    int i;
    int j;
    
    temp = malloc(stack->size * sizeof(int));
    i = -1;
    while (++i < stack->size)
        temp[i] = stack->numbers[i];
    i = -1;
    while (++i < stack->size - 1)
    {
        j = -1;
        while (++j < stack->size - i - 1)
        {
            if (temp[j] > temp[j + 1])
            {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    int median = temp[stack->size / 2];
    free(temp);
    return median;
}

static void perform_radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max_bits;
    int i;
    int j;

    normalize_array(stack_a->numbers, stack_a->size);
    max_bits = get_max_bits(stack_a);
    i = 0;
    while (i < max_bits)
    {
        int size = stack_a->size;
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
void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 5)
    {
        handle_small_stack(stack_a, stack_b);
        return;
    }
    perform_radix_sort(stack_a, stack_b);
}