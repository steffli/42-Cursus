/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:24:56 by stliu             #+#    #+#             */
/*   Updated: 2025/05/26 12:24:56 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	find_min(t_element *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

static void	sort_three(t_element **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot && top > bot)
		(sa(a), rra(a));
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
		(sa(a), ra(a));
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

static void	sort_five(t_element **a, t_element **b)
{
	while (list_len(*a) > 3)
	{
		if ((*a)->value == find_min(*a))
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	small_sort(t_element **a, t_element **b, int len)
{
	if (len == 2 && !is_sorted(*a))
		sa(a);
	else if (len == 3)
		sort_three(a);
	else if (len <= 5)
		sort_five(a, b);
}
