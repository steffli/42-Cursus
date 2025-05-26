/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:37:21 by stliu             #+#    #+#             */
/*   Updated: 2025/03/18 15:53:38 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Input: void pointer, size_t num
takes void pointer and sets the values to \0 for given num
same behavior as memset if give \0 as value
Returns original void pointer with \0 based on given num
*/
void	ft_bzero(void *ptr, size_t num)
{
	size_t			i;
	unsigned char	*p;

	p = ptr;
	i = 0;
	while (i < num)
	{
		*p = '\0';
		p++;
		i++;
	}
}
