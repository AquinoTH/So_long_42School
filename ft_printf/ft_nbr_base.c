/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:56:01 by taquino-          #+#    #+#             */
/*   Updated: 2024/01/09 17:56:01 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_nbr_base(long long num, char *base)
{
	int	bytes;
	int	size_base;

	bytes = 0;
	size_base = ft_strlen(base);
	if (num < 0)
	{
		bytes += ft_putchar('-');
		num = -num;
	}
	if (num >= size_base)
		bytes += ft_nbr_base((num / size_base), base);
	bytes += ft_putchar(base[num % size_base]);
	return (bytes);
}
