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
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
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
	second->next = first;
	*b = second;
	write(1, "sb\n", 3);
}

void	pa(t_element **a, t_element **b)
{
	t_element	*temp_b;

	if (!b || !(*b))
		return ;
	temp_b = *b;
	*b = temp_b->next;
	temp_b->next = *a;
	*a = temp_b;
	write(1, "pa\n", 3);
}

void	pb(t_element **a, t_element **b)
{
	t_element	*temp_a;

	if (!a || !(*a))
		return ;
	temp_a = *a;
	*a = temp_a->next;
	temp_a->next = *b;
	*b = temp_a;
	write(1, "pb\n", 3);
}

void	ss(t_element **a, t_element **b)
{
	return (sa(a), sb(b));
}
