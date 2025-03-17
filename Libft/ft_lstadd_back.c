/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:46:40 by stliu             #+#    #+#             */
/*   Updated: 2025/03/17 08:46:40 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
		return ;
	
	if (*lst == NULL)	
		*lst = new;
	ft_lstlast(*lst) -> next = new;
}