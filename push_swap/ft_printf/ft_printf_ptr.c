/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:06:49 by stliu             #+#    #+#             */
/*   Updated: 2025/03/25 17:28:37 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(unsigned long long n, int *count, int *error)
{
	if (n >= 16 && !(*error))
		print_ptr(n / 16, count, error);
	if (n % 16 < 10 && !(*error))
	{
		ft_putc(n % 16 + '0', error);
		(*count)++;
	}
	else if (!(*error))
	{
		ft_putc(n % 16 + 'a' - 10, error);
		(*count)++;
	}
}

void	ft_ptr(unsigned long long ptr, int *count, int *error)
{
	if (!(*error))
	{
		ft_putstr("0x", count, error);
		print_ptr((unsigned long long)ptr, count, error);
	}
}
