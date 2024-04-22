/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:15:38 by taquino-          #+#    #+#             */
/*   Updated: 2023/11/09 12:35:35 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		len_s;
	int			i;

	len_s = ft_strlen(s);
	i = 0;
	if (start >= len_s || len == 0)
		return (ft_strdup("\0"));
	if (start + len > len_s)
		len = len_s - start;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (s[i] != '\0' && len > 0)
	{
		substr[i] = s[start];
		i++;
		start++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
