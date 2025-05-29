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

static int	get_max_bits(t_element **stack)
{
	t_element	*tmp;
	int			max;
	int			min;
	int			max_bits;

	tmp = *stack;
	max = tmp->value;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	max -= min;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	assign_indexes(t_element *stack)
{
	t_element	*ptr;
	t_element	*current;
	int			value;
	int			count;

	ptr = stack;
	while (ptr)
	{
		current = stack;
		count = 0;
		value = ptr->value;
		while (current)
		{
			if (ptr->value > current->value)
				count++;
			current = current->next;
		}
		ptr->index = count;
		ptr = ptr->next;
	}
}

void	radix_sort(t_element **a, t_element **b)
{
	int	i;
	int	j;
	int	size;

	assign_indexes(*a);
	i = -1;
	size = list_len(*a);
	while (++i < get_max_bits(a))
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
