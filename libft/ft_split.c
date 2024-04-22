/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:29:09 by taquino-          #+#    #+#             */
/*   Updated: 2023/11/09 14:13:10 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_string(char const *s, char c)
{
	int	i;
	int	count_strings;

	i = 0;
	count_strings = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		count_strings++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (count_strings);
}

static int	ft_free(char	**matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (1);
}

static int	ft_strcalloc(char const *s, char c, char **matrix)
{
	int	i_string;
	int	str_len;
	int	i_matrix;

	i_string = 0;
	i_matrix = 0;
	while (s[i_string] != '\0')
	{
		str_len = 0;
		while (s[i_string] == c && s[i_string] != '\0')
			i_string++;
		while (s[i_string] != '\0' && s[i_string] != c)
		{
			str_len++;
			i_string++;
		}
		if (str_len != 0)
		{
			matrix[i_matrix] = (char *)ft_calloc((str_len + 1), sizeof(char));
			if (matrix[i_matrix] == NULL)
				return (ft_free(matrix));
		}
		i_matrix++;
	}
	return (0);
}

static void	ft_putsubstring(char const *s, char c, char **matrix)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (matrix[j])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			matrix[j][k] = s[i];
			i++;
			k++;
		}
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;

	splitted = (char **) ft_calloc((ft_count_string(s, c) + 1), sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	if (ft_strcalloc(s, c, splitted) == 1)
		return (NULL);
	ft_putsubstring(s, c, splitted);
	return (splitted);
}
