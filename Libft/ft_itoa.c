/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:50:56 by stliu             #+#    #+#             */
/*   Updated: 2025/03/13 18:38:56 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		if (n == 0)
			return (len);
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_check_neg(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;
	int		number_len;

	i = 0;
	number_len = ft_number_len(n);
	num = (char *)malloc((number_len + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	num[number_len] = '\0';
	if (ft_check_neg(n) == -1)
	{
		num[0] = '-';
		n = -n;
		i = 1;
	}
	else
		i = 0;
	while (n >= 10)
	{
		num[number_len--] = (n % 10) + '0';
		n /= 10;
	}
	num[number_len] = (n % 10) + '0';
	return (num);
}

int	main(void)
{
	int nb = 2147483647;
	char *nbb = ft_itoa(nb);
	puts(nbb);
	free(nbb);
}

// 0 edge case and max neg int