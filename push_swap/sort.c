/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: stliu <stliu@student.42heilbronn.de>       +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/05/26 11:50:27 by stliu             #+#    #+#             */
/*   Updated: 2025/05/26 11:50:27 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	is_sorted(t_element *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int get_max_bits(t_element *stack)
{
	int size;
	int max_bits;

	size = list_len(stack);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

static void assign_indexes(t_element *a)
{
	t_element *temp;
	t_element *current;
	int i;

	temp = a;
	while (temp)
	{
		current = a;
		i = 0;
		while (current)
		{
			if (temp->value > current->value)
				i++;
			current = current->next;
		}
		temp->index = i;
		temp = temp->next;
	}
}

void radix_sort(t_element **a, t_element **b)
{
	int max_bits;
	int size;
	int i;
	int j;

	assign_indexes(*a);
	max_bits = get_max_bits(*a);
	size = list_len(*a);
	while ((size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
	}
}
