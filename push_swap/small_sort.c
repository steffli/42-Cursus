/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: stliu <stliu@student.42heilbronn.de>       +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/05/26 12:24:56 by stliu             #+#    #+#             */
/*   Updated: 2025/05/26 12:24:56 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	find_min(t_element *stack)
{
	int			min;
	int			min_pos;
	int			current_pos;
	t_element	*current;

	min = stack->value;
	min_pos = 0;
	current_pos = 0;
	current = stack;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}

static void	min_top(t_element **a)
{
	int	min_pos;
	int	size;

	min_pos = find_min(*a);
	size = list_len(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			rra(a);
	}
}

static void	tripple_sort(t_element **a)
{
	int	one;
	int	two;
	int	three;

	one = (*a)->value;
	two = (*a)->next->value;
	three = (*a)->next->next->value;
	if (one > two && two > three)
	{
		sa(a);
		rra(a);
	}
	else if (one < two && two > three && one < three)
	{
		rra(a);
		sa(a);
	}
	else if (one > two && two < three && one > three)
		ra(a);
	else if (one > two && two < three && one < three)
		sa(a);
	else if (one < two && two > three && one > three)
		rra(a);
}

static void	quadro_k(t_element **a, t_element **b)
{
	min_top(a);
	pb(a, b);
	tripple_sort(a);
	pa(a, b);
}

static void	fiverr(t_element **a, t_element **b)
{
	min_top(a);
	pb(a, b);
	min_top(a);
	pb(a, b);
	tripple_sort(a);
	pa(a, b);
	pa(a, b);
}

void	small_sort(t_element **a, t_element **b, int len)
{
	if (len == 2 && !is_sorted(*a))
		sa(a);
	else if (len == 3)
		tripple_sort(a);
	else if (len == 4)
		quadro_k(a, b);
	else if (len == 5)
		fiverr(a, b);
}
