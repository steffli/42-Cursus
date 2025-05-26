/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:36:56 by stliu             #+#    #+#             */
/*   Updated: 2025/05/25 15:57:04 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*new_element(int value)
{
	t_element	*node;

	node = (t_element *)malloc(sizeof(t_element));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

int	list_len(t_element *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_element	*get_last_element(t_element *stack)
{
	t_element	*last_element;

	if (stack == NULL)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
		last_element = stack;
	}
	return (last_element);
}

int	add_node(t_element **stack, int num)
{
	t_element	*element;
	t_element	*last;

	element = new_element(num);
	if (!element)
		return (0);
	if (!*stack)
		return (*stack = element, 1);
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = element;
	last->previous = last;
	return (1);
}

int	create_stack(t_element **a, int argc, char **argv)
{
	char	**split_str;
	long	num;
	int		i;
	int		is_alloc;

	i = -1;
	is_alloc = 0;
	if (argc == 2)
	{
		split_str = ft_split(argv[1], ' ');
		is_alloc = 1;
	}
	else
		split_str = argv + 1;
	while (split_str[++i])
	{
		if (wrong_syntax(split_str[i]))
			return (free_split(split_str, is_alloc), 0);
		// if (ft_strlen(split_str[i]) > 10)
		// 	return (free_split(split_str, is_alloc), 0);
		num = ft_atol(split_str[i]);
		if (num < INT_MIN || num > INT_MAX || found_dupes(*a, (int)num))
			return (free_split(split_str, is_alloc), 0);
		if (!add_node(a, (int)num))
			return (free_split(split_str, is_alloc), 0);
	}
	free_split(split_str, is_alloc);
	return (1);
}
