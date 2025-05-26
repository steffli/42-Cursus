/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:56:18 by stliu             #+#    #+#             */
/*   Updated: 2025/03/25 17:29:10 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(char c, int *error)
{
	if (write(1, &c, 1) == -1)
	{
		*error = 1;
	}
	return (*error);
}

void	ft_putstr(char *s, int *count, int *error)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i] && !(*error))
	{
		ft_putc(s[i], error);
		(*count)++;
		i++;
	}
}

void	ft_hex(unsigned int n, int *count, const char *format, int *error)
{
	if (n >= 16 && !(*error))
		ft_hex(n / 16, count, format, error);
	if (n % 16 < 10 && !(*error))
	{
		ft_putc(n % 16 + '0', error);
		(*count)++;
	}
	else if (!(*error))
	{
		if (*format == 'X' && !(*error))
		{
			ft_putc(n % 16 + 'A' - 10, error);
			(*count)++;
		}
		else if (*format == 'x' && !(*error))
		{
			ft_putc(n % 16 + 'a' - 10, error);
			(*count)++;
		}
	}
}

void	ft_putnbr(int n, int *count, int *error)
{
	if (n == -2147483648 && !(*error))
	{
		ft_putstr("-2147483648", count, error);
		return ;
	}
	if (n < 0 && !(*error))
	{
		ft_putc('-', error);
		n = -n;
		(*count)++;
	}
	if (n >= 10 && !(*error))
		ft_putnbr(n / 10, count, error);
	if (*error)
		return ;
	ft_putc(n % 10 + '0', error);
	(*count)++;
}

void	ft_unsigned(unsigned int n, int *count, int *error)
{
	if (n >= 10 && !(*error))
		ft_unsigned(n / 10, count, error);
	if (*error)
		return ;
	ft_putc(n % 10 + '0', error);
	(*count)++;
}
