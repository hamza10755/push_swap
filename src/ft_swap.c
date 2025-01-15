/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:40:49 by hbelaih           #+#    #+#             */
/*   Updated: 2025/01/15 15:55:59 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_sa(t_stack *a, int print)
{
    int temp;
    if (a->size < 2)
        return ;
    temp = a->numbers[0];
    a->numbers[0] = a->numbers[1];
    a->numbers[1] = temp;
    if (print)
        write (1, "sa\n", 3);
}

void    ft_sb(t_stack *b, int print)
{
    int temp;
    if (b->size < 2)
        return ;
    temp = b->numbers[0];
    b->numbers[0] = b->numbers[1];
    b->numbers[1] = temp;
    if (print)
        write (1, "sb\n", 3);
}

void    ft_ss(t_stack *a, t_stack *b, int print)
{
    ft_sa(a, 0);
    ft_sb(b, 0);
    if (print)
        write (1, "ss\n", 3);
}

// int main(void)
// {
//     t_stack a;
//     t_stack b;
//     int numbers[] = {3, 2, 1};
//     int numbers2[] = {3, 2, 1};
    
//     b.numbers = numbers2;
//     a.numbers = numbers;
//     a.size = 3;
//     b.size = 3;

//     ft_ss(&a, &b, 1);
//     int i = 0;
//     while(i < a.size)
//     {
//         printf("%d ", a.numbers[i]);
//         printf("%d\n", b.numbers[i]);
//         i++;
//     }
//     printf("\n");

//     return 0;
// }