/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:05:10 by stliu             #+#    #+#             */
/*   Updated: 2025/03/12 18:27:46 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	count_delims(const char *s, char delim)
{
	int count;
	
	count = 0;
	while(*s)
	{
		if(*s == delim)
			count++;
		s++;
	}
	return (count);
}

char **ft_split(char const *s, char c)
{
	size_t	i;
	size_t j;
	char *str;
	char **arr;

	
	
	i = 0;
	while(s[i] != '\0' )
	{
		while(s[j] != c)
		{
			str[i] = s[i];
		}
		i++;
	}
}

int main()