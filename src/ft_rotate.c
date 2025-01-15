/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:57:58 by hbelaih           #+#    #+#             */
/*   Updated: 2025/01/15 16:26:50 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_ra(t_stack *a, int print)
{
    int     i;
    int     temp;

    if (a->size < 2)
        return ;
    i = 0;
    temp = a->numbers[0];
    while (i < a->size - 1)
    {
        a->numbers[i] = a->numbers[i + 1];
        i++;
    }
    a->numbers[i] = temp;
    if (print)
        write (1, "ra\n", 3);
}

void    ft_rb(t_stack *b, int print)
{
    int     i;
    int     temp;

    if (b->size < 2)
        return ;
    i = 0;
    temp = b->numbers[0];
    while (i < b->size - 1)
    {
        b->numbers[i] = b->numbers[i + 1];
        i++;
    }
    b->numbers[i] = temp;
    if (print)
        write (1, "rb\n", 3);
}

void    ft_rr(t_stack *a, t_stack *b, int print)
{
    ft_ra(a, 0);
    ft_rb(b, 0);
    if (print)
        write (1, "rr\n", 3);
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

//     ft_ra(&a, 1);
//     ft_rb(&b, 1);
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
