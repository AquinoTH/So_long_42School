/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:32:43 by taquino-          #+#    #+#             */
/*   Updated: 2023/11/09 12:32:43 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (((char *)s)[i] != (char)c)
	{
		if (((char *)s)[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

/*
#include <stdio.h>
int	main(void)
{
    const char    *str = "Hello world";

    printf ("%s\n", ft_strchr(str, 'r'));
    return (0);
}
*/