/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:17:15 by taquino-          #+#    #+#             */
/*   Updated: 2023/11/09 12:30:15 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_sign(int n)
{
	if (n < 0)
	{
		return (1);
	}
	else
		return (0);
}

static size_t	ft_get_lenght(size_t n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		nbr;
	unsigned int	sign_result;
	unsigned int	strlen;

	sign_result = ft_get_sign(n);
	nbr = n;
	if (sign_result == 1)
		nbr = nbr * -1;
	strlen = ft_get_lenght(nbr);
	str = (char *)malloc(sizeof(char) * (strlen + sign_result + 1));
	if (str == NULL)
		return (NULL);
	if (sign_result == 1)
		str[0] = '-';
	str[strlen + sign_result] = '\0';
	while (strlen > 0)
	{
		str[(strlen + sign_result) - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		strlen--;
	}
	return (str);
}
