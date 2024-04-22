/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:49:14 by taquino-          #+#    #+#             */
/*   Updated: 2024/04/22 17:49:15 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long_bonus.h"

void	ft_move_down(t_game *game)
{
	char	tile;

	tile = game->map.mgrid[game->map.jplayer + 1][game->map.iplayer];
	if (tile != '1')
	{
		game->move_count++;
		game->char_direction = 'F';
		game->map.jplayer++;
	}
	move_conditionals(game, tile);
}

void	ft_move_up(t_game *game)
{
	char	tile;

	tile = game->map.mgrid[game->map.jplayer - 1][game->map.iplayer];
	if (tile != '1')
	{
		game->move_count++;
		game->char_direction = 'B';
		game->map.jplayer--;
	}
	move_conditionals(game, tile);
}

void	ft_move_right(t_game *game)
{
	char	tile;

	tile = game->map.mgrid[game->map.jplayer][game->map.iplayer + 1];
	if (tile != '1')
	{
		game->move_count++;
		game->char_direction = 'R';
		game->map.iplayer++;
	}
	move_conditionals(game, tile);
}

void	ft_move_left(t_game *game)
{
	char	tile;

	tile = game->map.mgrid[game->map.jplayer][game->map.iplayer - 1];
	if (tile != '1')
	{
		game->move_count++;
		game->char_direction = 'L';
		game->map.iplayer--;
	}
	move_conditionals(game, tile);
}

void	move_conditionals(t_game *game, char tile)
{
	if (tile == 'C')
	{
		game->map.mgrid[game->map.jplayer][game->map.iplayer] = '0';
		game->collected++;
	}
	if (tile == 'E' && game->collected == game->map.count_c)
	{
		ft_printf("You won! Number of movements: %d\n", game->move_count);
		ft_close_window(game);
	}
	if (tile == 'X')
	{
		ft_printf("You were killed by an enemy. RIP :(", game->move_count);
		game->char_direction = 'D';
		return ;
	}
	ft_printf("moves: %d\r", game->move_count);
}
