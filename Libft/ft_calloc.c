/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:27:51 by stliu             #+#    #+#             */
/*   Updated: 2025/03/11 22:27:51 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;
	size_t i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if(ptr == NULL)
		return NULL;
	while(i < nmemb * size)
		{
			((char *)ptr)[i] = '\0';
			i++;
		}
	
	return (ptr);
}
