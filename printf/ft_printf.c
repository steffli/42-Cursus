/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:50:19 by stliu             #+#    #+#             */
/*   Updated: 2025/03/21 15:58:05 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check_format(va_list args, const char *format, int *count)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (*format == 'c')
	{
		ft_putc(va_arg(args, int));
		(*count)++;
	}
	else if (*format == 'p')
	{
		ft_putstr("0x", count);
		ft_hex(va_arg(args, unsigned long), count);
	}
	else if (*format == 'u')
		ft_putnbr(va_arg(args, unsigned int), count);
	else if (*format == 'x' || *format == 'X')
		ft_hex(va_arg(args, unsigned int), count);
	else if (*format == '%')
	{
		ft_putc('%');
		(*count)++;
	}
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_format(args, format, &count);
			format++;
		}
		else
		{
			ft_putc(*format);
			count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int  a = ft_printf("%s", "hallo");
// 	ft_printf("%d", a);
// 	return (0);
// }