/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:49:04 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/21 00:25:29 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->numbers)
			free(stack->numbers);
		free(stack);
	}
}

static int	is_valid_number_format(char *str, int *i, int *sign)
{
	*i = 0;
	*sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (!str[*i])
		return (0);
	while (str[*i])
	{
		if (!ft_isdigit(str[*i]))
			return (0);
		(*i)++;
	}
	return (1);
}

int	is_number(char *str)
{
	int		i;
	long	num;
	int		sign;
	int		j;

	if (!is_valid_number_format(str, &i, &sign))
		return (0);
	num = 0;
	j = 0;
	while (str[j] == '+' || str[j] == '-')
		j++;
	while (str[j])
	{
		if ((num > 2147483647 / 10) || (num == 2147483647 / 10 && (str[j]
					- '0') > 2147483647 % 10))
			return (0);
		num = num * 10 + (str[j] - '0');
		j++;
	}
	if ((sign == 1 && num > 2147483647) || (sign == -1 && (-num) < -2147483648))
		return (0);
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->numbers[i] == stack->numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->numbers[i] > stack->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}
