/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:31:35 by taquino-          #+#    #+#             */
/*   Updated: 2023/10/19 15:13:32 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;

	dest_len = ft_strlen(dest);
	src_len = 0;
	if (size <= ft_strlen(dest))
	{
		return (size + ft_strlen(src));
	}
	while ((src[src_len] != '\0') && (dest_len + 1 < size))
	{
		dest[dest_len] = src[src_len];
		dest_len++;
		src_len++;
	}
	dest[dest_len] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[src_len]));
}
