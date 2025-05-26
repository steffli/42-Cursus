/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:28:26 by stliu             #+#    #+#             */
/*   Updated: 2025/04/07 14:53:02 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		check_format(va_list args, const char *format, int *count, int *error);
int		ft_putc(char c, int *error);
void	ft_putstr(char *s, int *count, int *error);
void	ft_hex(unsigned int n, int *count, const char *format, int *error);
void	ft_putnbr(int n, int *count, int *error);
void	ft_unsigned(unsigned int n, int *count, int *error);
void	ft_ptr(unsigned long long ptr, int *count, int *error);

#endif