/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:56:13 by taquino-          #+#    #+#             */
/*   Updated: 2024/01/09 17:56:13 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_ptr_base(unsigned long num, char *base)
{
	int	bytes;
	int	size_base;

	if (num == 0)
		return (ft_putstr("(nil)"));
	bytes = 0;
	size_base = ft_strlen(base);
	if (num >= (unsigned long)size_base)
		bytes += ft_ptr_base((num / size_base), base);
	else
		bytes += ft_putstr("0x");
	bytes += ft_putchar(base[num % size_base]);
	return (bytes);
}
