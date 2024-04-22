/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:13:17 by taquino-          #+#    #+#             */
/*   Updated: 2024/01/11 18:41:07 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing(char format, va_list ap)
{
	int	bytes;

	bytes = 0;
	if (format == 'c')
		bytes += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		bytes += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		bytes += ft_ptr_base(va_arg(ap, unsigned long), HEXA_LOWER_BASE);
	else if (format == 'd' || format == 'i')
		bytes += ft_nbr_base(va_arg(ap, int), DECIMAL_BASE);
	else if (format == 'u')
		bytes += ft_nbr_base(va_arg(ap, unsigned int), DECIMAL_BASE);
	else if (format == 'x')
		bytes += ft_nbr_base(va_arg(ap, unsigned int), HEXA_LOWER_BASE);
	else if (format == 'X')
		bytes += ft_nbr_base(va_arg(ap, unsigned int), HEXA_UPPER_BASE);
	else if (format == '%')
		bytes += ft_putchar('%');
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		bytes;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	bytes = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			bytes += ft_parsing(format[++i], ap);
		else
			bytes += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (bytes);
}
