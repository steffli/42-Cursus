/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:50:53 by stliu             #+#    #+#             */
/*   Updated: 2025/05/14 15:00:38 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if input is a number
int	wrong_syntax(char *str)
{
	if (!*str || *str == '\0')
		return (1);
	if (*str == '+' || *str == '-')
		str++;
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

//free node and free stack

int	found_dupes(t_element *a, int nbr)
{
	t_element	*current;

	current = a;
	while (current->next)
	{
		if (current->value == nbr)
			return (1);
		current = current->next;
	}
	if (current->value == nbr)
		return (1);
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

void	free_exit(t_element **a, char **argv, int is_split)
{
	int	i;

	i = 0;
	free_stack(a);
	if (argv && is_split)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	ft_printf("Error\n");
	exit(1);
}

void	free_split(char **split_str)
{
	int	i;

	if (!split_str)
		return ;
	i = 0;
	while (split_str[i])
		free(split_str[i++]);
	free(split_str);
}