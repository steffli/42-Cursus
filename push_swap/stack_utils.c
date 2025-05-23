/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:36:56 by stliu             #+#    #+#             */
/*   Updated: 2025/05/23 15:57:09 by stliu            ###   ########.fr       */
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

int	add_node(t_element **stack, int nbr)
{
	t_element	*element;
	t_element	*last;

	element = new_element(nbr);
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

int	create_stack(t_element **a, char **argv)
{
	int	nbr;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (wrong_syntax(argv[i]))
			return (0);
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (0);
		if (found_dupes(*a, (int)nbr))
			return (0);
		if (!add_node(a, (int)nbr))
			return (0);
		i++;
	}
	return (1);
}
