/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
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

static void	apply_offset(t_element **stack, int offset)
{
	t_element	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->value += offset;
		tmp = tmp->next;
	}
}

void	radix_sort(t_element **a, t_element **b)
{
	t_element	*tmp;
	int			i;
	int			j;
	int			size;
	int			max_bits;
	int			min_val;
	int			offset;

	tmp = *a;
	min_val = tmp->value;
	while (tmp)
	{
		if (tmp->value < min_val)
			min_val = tmp->value;
		tmp = tmp->next;
	}
	offset = (min_val < 0) ? -min_val : 0;
	if (offset > 0)
		apply_offset(a, offset);
	i = 0;
	size = list_len(*a);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			tmp = *a;
			if (((tmp->value >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		i++;
	}
	if (offset > 0)
		apply_offset(a, -offset);
}