/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:11:41 by taquino-          #+#    #+#             */
/*   Updated: 2023/10/31 14:03:14 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*array;

	total_size = (nmemb * size);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (total_size / size != nmemb)
		return (NULL);
	array = malloc(total_size);
	if (!array)
		return (NULL);
	ft_bzero(array, total_size);
	return (array);
}
