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
	return (1);
}

int create_stack(t_element **a, int argc, char **argv)
{
    char    **split_str;
    long    num;
    int     i;
    int     j;

    i = 0;
    while (++i < argc)
    {
        split_str = ft_split(argv[i], ' ');
        if (!split_str)
            return (free_stack(a), 0);
        j = -1;
        while (split_str[++j])
        {
            if (wrong_syntax(split_str[j]) || !ft_strlen(split_str[j]))
                return (free_stack(a), free_split(split_str, 1), 0);
            num = ft_atol(split_str[j]);
            if (num < INT_MIN || num > INT_MAX || found_dupes(*a, (int)num))
                return (free_stack(a), free_split(split_str, 1), 0);
            if (!add_node(a, (int)num))
                return (free_stack(a), free_split(split_str, 1), 0);
        }
        free_split(split_str, 1);
    }
    return (1);
}
