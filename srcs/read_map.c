/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:47:43 by taquino-          #+#    #+#             */
/*   Updated: 2024/04/25 19:38:56 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_length(char *map_file)
{
	int		map_length;
	int		bytes_readed;
	char	buf;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	map_length = 0;
	bytes_readed = 1;
	while (bytes_readed != 0)
	{
		bytes_readed = read(fd, &buf, 1);
		if (bytes_readed == -1)
			return (0);
		map_length++;
	}
	close(fd);
	map_length--;
	return (map_length);
}

void	ft_set_map_variables(t_game *game)
{
	game->map.mheight = 0;
	game->map.mwidth = 0;
	game->map.count_c = 0;
	game->map.count_p = 0;
	game->map.count_e = 0;
	game->map.charvalidation = 0;
}

int	ft_read_map(t_game *game)
{
	int		bytes_readed;
	char	*map_array;
	int		map_length;
	int		fd;

	ft_set_map_variables(game);
	map_length = ft_map_length(game->map.mfile);
	if (map_length == -1)
		return (-1);
	fd = open(game->map.mfile, O_RDONLY);
	map_array = malloc((map_length + 1) * sizeof(char));
	if (!map_array)
		return (0);
	bytes_readed = 1;
	bytes_readed = read(fd, map_array, map_length);
	if (bytes_readed == -1)
	{
		free(map_array);
		return (-1);
	}
	map_array[map_length] = '\0';
	game->map.mgrid = ft_split(map_array, '\n');
	close(fd);
	free(map_array);
	return (0);
}
