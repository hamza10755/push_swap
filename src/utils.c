/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:49:04 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/16 22:33:48 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_stack(t_stack *stack)
{
    if (stack)
    {
        if (stack->numbers)
            free(stack->numbers);
        free(stack);
    }
}

int is_number(char *str)
{
    int i;
    long num;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    num = ft_atoi(str);
    if (num > INT_MAX || num < INT_MIN)
        return (0);
    return (1);
}

int has_duplicates(t_stack *stack)
{
    int i;
    int j;
    
    i = 0;
    while (i < stack->size)
    {
        j = i + 1;
        while (j < stack->size)
        {
            if (stack->numbers[i] == stack->numbers[j])
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

int is_sorted(t_stack *stack)
{
    int i;
    
    i = 0;
    while (i < stack->size - 1)
    {
        if (stack->numbers[i] > stack->numbers[i + 1])
            return 0;
        i++;
    }
    return 1;
}

void normalize_stack(t_stack *stack, int *min)
{
    int i;
    
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
