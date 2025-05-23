/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:34:57 by stliu             #+#    #+#             */
/*   Updated: 2025/05/23 16:00:33 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
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

static void	free_split(char **split_str)
{
	if (!split_str)
		return ;
	while (*split_str)
	{
		free(*split_str);
		split_str++;
	}
	free(split_str);
}
int	main(int argc, char **argv)
{
    t_element	*a;
    t_element	*b;
    char		**split_str;
    int			is_split;

    a = NULL;
    b = NULL;
    is_split = 0;

    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        return (1);

    // Handle single argument (split string)
    if (argc == 2)
    {
        split_str = ft_split(argv[1], ' ');
        if (!split_str || !split_str[0]) // Check for empty or invalid split
        {
            free_split(split_str);
            ft_printf("Error\n");
            return (1);
        }
        is_split = 1;
        if (!create_stack(&a, split_str))
            free_exit(&a, split_str, is_split); // Pass split_str to free_exit
        free_split(split_str); // Free split_str after successful stack creation
    }

    // Handle multiple arguments
    else if (!create_stack(&a, argv + 1))
        free_exit(&a, NULL, 0);

    // Print stack for debugging
    print_stack(a, "a");

    // Free the stack
    free_stack(&a);
    free_stack(&b);
    return (0);
}