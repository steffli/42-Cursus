/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:38:35 by stliu             #+#    #+#             */
/*   Updated: 2025/03/17 16:27:12 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
goes through lst and applies f to each not , creates new list resulting of 
succesive app of f and del function if needed

if new node creation fails 
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list 

	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
		ft_lstiter(lst, f(lst->content));
}

