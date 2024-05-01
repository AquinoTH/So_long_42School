/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:47:59 by taquino-          #+#    #+#             */
/*   Updated: 2024/04/29 17:03:16 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (ft_input_validation(argc, argv[1]) != 0)
		return (0);
	game.map.mfile = argv[1];
	if (ft_read_map(&game) == -1)
		return (ft_printf("Unable to open the informed map file. "
				"Please check if informed path is correct.\n"));
	if (ft_check_map(&game) < 0)
		return (ft_end_game(game, 0));
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
	{
		ft_printf("Error while initializing mlx.\n");
		return (ft_end_game(game, 0));
	}
	render_img(&game);
	render_img_coin(&game);
	initialize_game_variables(&game);
	if (open_window(&game) != 0)
		ft_end_game(game, 2);
	mlx_key_hook(game.win_ptr, &handle_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, NoEventMask, &ft_close_window, &game);
	mlx_loop_hook(game.mlx_ptr, &render, &game);
	mlx_loop(game.mlx_ptr);
}
