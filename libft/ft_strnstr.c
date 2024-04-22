/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:41:17 by taquino-          #+#    #+#             */
/*   Updated: 2023/10/24 14:40:34 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;

	l = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	while (*big && l <= len)
	{
		if ((*big == *little) && (ft_strncmp(big, little, l) == 0))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
