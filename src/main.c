/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:42:00 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/16 22:23:54 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack *create_stack(int capacity)
{
    t_stack *stack;

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

static void init_stack_a(t_stack *stack_a, int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        stack_a->numbers[stack_a->size++] = ft_atoi(argv[i]);
        i++;
    }
}

static void check_args(t_stack *stack_a, t_stack *stack_b)
{
    if (has_duplicates(stack_a))
        clean_exit(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    int i;

    if (argc < 2)
        return 0;
    t_stack *stack_a = create_stack(argc - 1);
    t_stack *stack_b = create_stack(argc - 1);
    if (!stack_a || !stack_b)
        error_exit();
    i = 1;
    while (i < argc)
    {
        if (!is_number(argv[i]))
            clean_exit(stack_a, stack_b);
        i++;
    }
    init_stack_a(stack_a, argc, argv);
    check_args(stack_a, stack_b);
    sort_stack(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}

