/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:19:39 by stliu             #+#    #+#             */
/*   Updated: 2025/05/14 14:19:09 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_element **a)
{
	t_element	*last;
	t_element	*second_last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_element **b)
{
	t_element	*last;
	t_element	*second_last;

	if (!(*b) || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

void	ra(t_element **a)
{
	t_element	*first;
	t_element	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first ->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_element **b)
{
	t_element	*first;
	t_element	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first ->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_element **a, t_element **b)
{
	return (ra(a), rb(b));
}
