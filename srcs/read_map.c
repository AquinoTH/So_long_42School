/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:47:43 by taquino-          #+#    #+#             */
/*   Updated: 2024/04/22 17:47:44 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

int	ft_maplen(char *mapfile)
{
	int		maplen;
	int		read_result;
	char	buf;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (-1);
	maplen = 0;
	read_result = 1;
	while (read_result != 0)
	{
		read_result = read(fd, &buf, 1);
		if (read_result == -1)
			return (0);
		maplen++;
	}
	close(fd);
	maplen--;
	return (maplen);
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
	int		read_result;
	char	*maparray;
	int		maplen;
	int		fd;

	ft_set_map_variables(game);
	maplen = ft_maplen(game->map.mfile);
	if (maplen == -1)
		return (-1);
	fd = open(game->map.mfile, O_RDONLY);
	maparray = malloc((maplen + 1) * sizeof(char));
	if (!maparray)
		return (0);
	read_result = 1;
	read_result = read(fd, maparray, maplen);
	if (read_result == -1)
	{
		free(maparray);
		return (-1);
	}
	maparray[maplen] = '\0';
	game->map.mgrid = ft_split(maparray, '\n');
	close(fd);
	free(maparray);
	return (0);
}
