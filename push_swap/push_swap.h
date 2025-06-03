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
	int				index;
	struct s_node	*next;
}					t_element;
// Push_swap operations
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

//Input checker
int					wrong_syntax(char *str);
int					found_dupes(t_element *a, int nbr);
long				ft_atol(char *str);

//Stack utilities
int					create_stack(t_element **a, int argc, char **argv);
void				free_stack(t_element **a);
void				free_split(char **split_str, int is_split);

//Sorting utilities
int					is_sorted(t_element *stack);
int					list_len(t_element *stack);
void				small_sort(t_element **a, t_element **b, int len);
void				radix_sort(t_element **a, t_element **b);

#endif
