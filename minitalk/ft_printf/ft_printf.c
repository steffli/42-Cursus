/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:50:19 by stliu             #+#    #+#             */
/*   Updated: 2025/04/07 14:53:56 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, const char *format, int *count, int *error)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), count, error);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), count, error);
	else if (*format == 'c')
	{
		ft_putc(va_arg(args, int), error);
		(*count)++;
	}
	else if (*format == 'p')
		ft_ptr(va_arg(args, unsigned long long), count, error);
	else if (*format == 'u')
		ft_unsigned(va_arg(args, unsigned long), count, error);
	else if (*format == 'x' || *format == 'X')
		ft_hex(va_arg(args, unsigned long), count, format, error);
	else if (*format == '%')
	{
		ft_putc('%', error);
		(*count)++;
	}
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		error;

	count = 0;
	error = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			count = check_format(args, ++format, &count, &error);
			if (error)
				return (-1);
		}
		else
		{
			ft_putc(*format, &error);
			if (error)
				return (-1);
			count++;
		}
		format++;
	}
	return (va_end(args), count);
}
