/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:47:18 by taquino-          #+#    #+#             */
/*   Updated: 2024/04/25 19:38:34 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_img(t_game *game)
{
	if (game->map.exit_open_img)
		mlx_destroy_image(game->mlx_ptr, game->map.exit_open_img);
	if (game->map.exit_closed_img)
		mlx_destroy_image(game->mlx_ptr, game->map.exit_closed_img);
	if (game->map.grass_img)
		mlx_destroy_image(game->mlx_ptr, game->map.grass_img);
	if (game->map.char_back_img)
		mlx_destroy_image(game->mlx_ptr, game->map.char_back_img);
	if (game->map.char_front_img)
		mlx_destroy_image(game->mlx_ptr, game->map.char_front_img);
	if (game->map.char_right_img)
		mlx_destroy_image(game->mlx_ptr, game->map.char_right_img);
	if (game->map.char_left_img)
		mlx_destroy_image(game->mlx_ptr, game->map.char_left_img);
	if (game->map.wall_img)
		mlx_destroy_image(game->mlx_ptr, game->map.wall_img);
	if (game->map.first_wall_img)
		mlx_destroy_image(game->mlx_ptr, game->map.first_wall_img);
}

void	ft_destroy_img_coin(t_game *game)
{
	int	i_coin;

	i_coin = 0;
	while (i_coin < 16)
	{
		if (game->map.coin_img[i_coin])
			mlx_destroy_image(game->mlx_ptr, game->map.coin_img[i_coin]);
		i_coin++;
	}
}
