/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:57:16 by taquino-          #+#    #+#             */
/*   Updated: 2024/01/09 17:57:16 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_putchar(char c)
{
	int	bytes;

	bytes = write(1, &c, 1);
	return (bytes);
}

int	ft_putstr(char *str)
{
	int	len_str;
	int	bytes;

	if (!str)
		return (write(1, "(null)", 6));
	len_str = ft_strlen(str);
	bytes = write(1, str, len_str);
	return (bytes);
}
