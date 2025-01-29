/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:34:18 by hamzabillah       #+#    #+#             */
/*   Updated: 2025/01/30 01:50:14 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_stacks(char **numbers, int count, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	if (i == 0)
	{
		if (count == 1)
			free_split(numbers);
		error_exit();
	}
	*stack_a = create_and_init_stack(i);
	*stack_b = create_and_init_stack(i);
	if (!*stack_a || !*stack_b)
	{
		if (count == 1)
			free_split(numbers);
		error_exit();
	}
}

static void	fill_stack(char **numbers, int count, t_stack **stack_a, t_stack **stack_b)
{
	int	j;

	if (count == 1)
		j = 0;
	else
		j = 1;
	while (numbers[j])
	{
		if (!is_number(numbers[j]))
		{
			if (count == 1)
				free_split(numbers);
			clean_exit(*stack_a, *stack_b);
		}
		(*stack_a)->numbers[(*stack_a)->size++] = ft_atoi(numbers[j]);
		j++;
	}
	if (has_duplicates(*stack_a))
	{
		if (count == 1)
			free_split(numbers);
		clean_exit(*stack_a, *stack_b);
	}
}

static void	handle_single_argument(char *arg, t_stack **stack_a, t_stack **stack_b)
{
	char	**numbers;
	int		i;

	i = 0;
	while (arg[i])
		i++;
	while (i > 0 && arg[i - 1] == ' ')
		i--;
	if (i == 0)
		error_exit();
	arg[i] = '\0';
	numbers = ft_split(arg, ' ');
	if (!numbers)
		error_exit();
	init_stacks(numbers, 1, stack_a, stack_b);
	fill_stack(numbers, 1, stack_a, stack_b);
	free_split(numbers);
}

static void	handle_multiple_arguments(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	init_stacks(argv, argc, stack_a, stack_b);
	fill_stack(argv, argc, stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		handle_single_argument(argv[1], &stack_a, &stack_b);
	else
		handle_multiple_arguments(argc, argv, &stack_a, &stack_b);
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
