/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:13:36 by stliu             #+#    #+#             */
/*   Updated: 2025/03/11 22:13:36 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
char *ft_strdup(const char *s)
{
	int i;
	char *ptr;
	
	i = 0;
	while(s[i] != '\0')
		i++;
	//strlen
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while(s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';

	return (ptr);
}

// int main ()
// {
// 	char *s1  = "String";
// 	char *s2  = ft_strdup(s1);
// 	printf("%s", s2);
// }