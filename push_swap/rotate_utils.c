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
	last->previous = NULL;
	last->next = *a;
	(*a)->previous = last;
	*a = last;
	ft_printf("rra\n");
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
	last->previous = NULL;
	last->next = *b;
	(*b)->previous = last;
	*b = last;
	ft_printf("rrb\n");
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
	(*a)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	ft_printf("ra\n");
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
	(*b)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_element **a, t_element **b)
{
	return (ra(a), rb(b));
}
