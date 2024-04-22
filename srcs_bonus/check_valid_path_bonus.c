/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:48:35 by taquino-          #+#    #+#             */
/*   Updated: 2024/04/22 17:48:36 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long_bonus.h"

int	ft_check_valid_path(t_game	*game)
{
	int	i;
	int	j;

	if (ft_dfs_setup(game))
		return (-1);
	ft_dfs_walls(game);
	i = game->map.iplayer;
	j = game->map.jplayer;
	while (!stop(game))
	{
		if (game->map.mgrid[j][i] == 'E' && game->map.visited[j][i] == 0)
			game->map.e_dfs++;
		if (game->map.mgrid[j][i] == 'C' && game->map.visited[j][i] == 0)
			game->map.c_dfs++;
		game->map.visited[j][i] = 1;
		if (ft_move_forward(game, &i, &j) != 0)
		{
			game->map.visited[j][i] = 2;
			move_backwards(game, &i, &j, game->map.parent[j][i]);
		}
	}
	if (game->map.e_dfs == 1 && game->map.c_dfs == game->map.count_c)
		return (ft_free_dfs(game));
	else
		return (ft_free_dfs(game) - 1);
}
