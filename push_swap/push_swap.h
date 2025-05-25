/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:14:06 by stliu             #+#    #+#             */
/*   Updated: 2025/05/25 15:33:57 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}					t_element;

void				sa(t_element **a);
void				sb(t_element **b);
void				ss(t_element **a, t_element **b);
void				pa(t_element **a, t_element **b);
void				pb(t_element **a, t_element **b);
void				ra(t_element **a);
void				rb(t_element **b);
void				rr(t_element **a, t_element **b);
void				rra(t_element **a);
void				rrb(t_element **b);
void				rrr(t_element **a, t_element **b);

int					wrong_syntax(char *str);
void				free_stack(t_element **a);
int					found_dupes(t_element *a, int nbr);
long				ft_atol(char *str);
int					create_stack(t_element **a, int argc, char **argv);
void				free_split(char **split_str, int is_split);

#endif
