/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:53:33 by hbelaih           #+#    #+#             */
/*   Updated: 2025/01/15 16:32:45 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_pa(t_stack *a, t_stack *b)
{
    int     i;
    if (b->size == 0)
        return ;
    i = a->size;
    while (i > 0)
    {
        a->numbers[i] = a->numbers[i - 1];
        i--;
    }
    a->numbers[0] = b->numbers[0];
    a->size++;
    b->size--;
    write (1, "pa\n", 3);
}

void    ft_pb(t_stack *a, t_stack *b)
{
    int     i;
    if (a->size == 0)
        return ;
    i = b->size;
    while (i > 0)
    {
        b->numbers[i] = b->numbers[i - 1];
        i--;
    }
    b->numbers[0] = a->numbers[0];
    b->size++;
    a->size--;
    write (1, "pb\n", 3);
}

int main(void)
{
    t_stack a;
    t_stack b;

    int numbers[] = {3, 2, 1};
    //int numbers2[] = {3, 2, 1};

    //b.numbers = numbers2;
    a.numbers = numbers;
    a.size = 3;
    b.size = 3;

    ft_pa(&a, &b);
    //ft_pb(&b, &b);
    int i = 0;
    while(i < a.size)
    {
        printf("%d ", a.numbers[i]);
        //printf("%d\n", b.numbers[i]);
        i++;
    }
    printf("\n");

    return 0;
}
