/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:50:19 by stliu             #+#    #+#             */
/*   Updated: 2025/03/24 16:52:23 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check_format(va_list args, const char *format, int *count)
{
	int error;

	error = 0;
	if (*format == 'd' || *format == 'i')
		error = ft_putnbr(va_arg(args, int), count);
	else if (*format == 's')
		error = ft_putstr(va_arg(args, char *), count);
	else if (*format == 'c')
		error = ft_putc(va_arg(args, int));
	else if (*format == 'p')
		error = ft_ptr(va_arg(args, unsigned long long), count);
	else if (*format == 'u')
		error = ft_unsigned(va_arg(args, unsigned long), count);
	else if (*format == 'x' || *format == 'X')
		error = ft_hex(va_arg(args, unsigned long), count, format);
	else if (*format == '%')
		error = ft_putc('%', count);
	if (error == -1)
		return (-1);
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		error;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			error = check_format(args, ++format, &count);
		else
			error = ft_putc(*format, &count);
		format++;
	}
	if (error == -1)
	{	
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	//printf("%d", 42);
// 	//printf("%p", -1);
// 	return (0);
// }