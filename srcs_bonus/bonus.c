/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:48:29 by taquino-          #+#    #+#             */
/*   Updated: 2024/04/29 17:09:53 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_img_enemy(t_game *game)
{
	game->map.enemy_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/enemy.xpm", &game->map.x_tile, &game->map.y_tile);
	game->map.rip_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/rip.xpm", &game->map.x_tile, &game->map.y_tile);
	if (!game->map.enemy_img || !game->map.rip_img)
		return (ft_printf("Error while creating image.\n"));
	return (0);
}
