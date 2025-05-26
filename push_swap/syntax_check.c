/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:50:53 by stliu             #+#    #+#             */
/*   Updated: 2025/05/25 15:53:14 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if input is a number
int	wrong_syntax(char *str)
{
	if (!str || *str == '\0')
		return (1);
	if (*str == '+' || *str == '-')
	{
		str++;
		if (*str == '+' || *str == '-')
			return (1);
	}
	if (!*str)
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

int	found_dupes(t_element *stack, int nbr)
{
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_element **a)
{
	t_element	*current;
	t_element	*next;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*a = NULL;
}

void	free_split(char **split_str, int is_alloced)
{
	int	i;

	if (is_alloced && split_str)
	{
		i = 0;
		while (split_str[i])
			free(split_str[i++]);
		free(split_str);
	}
}