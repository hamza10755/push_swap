/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:49:37 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/16 20:46:35 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void clean_exit(t_stack *stack_a, t_stack *stack_b)
{
    free_stack(stack_a);
    free_stack(stack_b);
    error_exit();
}