/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:22:30 by stliu             #+#    #+#             */
/*   Updated: 2025/05/14 14:19:33 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_element **a)
{
	t_element	*first;
	t_element	*second;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	*a = second;
	ft_printf("sa\n");
}

void	sb(t_element **b)
{
	t_element	*first;
	t_element	*second;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	*b = second;
	ft_printf("sb\n");
}

void	pa(t_element **a, t_element **b)
{
	t_element	*temp_b;

	if (!b || !(*b))
		return ;
	temp_b = *b;
	*b = temp_b->next;
	if (*b)
		(*b)->previous = NULL;
	temp_b->next = *a;
	if (*a)
		(*a)->previous = temp_b;
	*a = temp_b;
	ft_printf("pa\n");
}

void	pb(t_element **a, t_element **b)
{
	t_element	*temp_a;

	if (!a || !(*a))
		return ;
	temp_a = *a;
	*a = temp_a->next;
	if (*a)
		(*a)->previous = NULL;
	temp_a->next = *b;
	if (*b)
		(*b)->previous = temp_a;
	*b = temp_a;
	ft_printf("pb\n");
}

void	ss(t_element **a, t_element **b)
{
	return (sa(a), sb(b));
}
