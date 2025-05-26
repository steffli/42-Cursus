/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:34:57 by stliu             #+#    #+#             */
/*   Updated: 2025/05/25 15:48:40 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str <= 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

//#include <stdio.h>

void	print_stack(t_element *stack, const char *stack_name)
{
	ft_printf("Stack %s:\n", stack_name);
	if (!stack)
	{
		ft_printf("  (empty)\n");
		return ;
	}
	while (stack)
	{
		ft_printf("  %d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_element	*a;
	t_element	*b;

	a = NULL;
	b = NULL;
	(void)b;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	if (!create_stack(&a, argc, argv))
		return (free_stack(&a), ft_printf("Error\n"), 1);
	if (!is_sorted(a))
	{
		if (list_len(a) <= 5)
			small_sort(&a, &b, list_len(a));
		else
			radix_sort(&a, &b);
	}
	print_stack(a, "A");
	free_stack(&a);
	return (0);
}
