/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:08:57 by taquino-          #+#    #+#             */
/*   Updated: 2024/04/22 11:46:48 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_error(t_data *data, char *str, int num)
{
	if (num)
		ft_free_double_pointer(data);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	printf("--------------------------------------------------\n");
	printf("|              You gave up :(                    |\n");
	printf("|   Is the game hard for you? Try again......    |\n");
	printf("--------------------------------------------------\n");
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

static int	ft_render_next_frame(t_data *data)
/* I made this function to check for keyboard or mouse input */
{
	ft_put_background(data);
	ft_create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

void	check_filename(char *file_name)
{
	file_name = file_name + (ft_strlen(file_name) - 4);
	if (ft_strncmp(file_name, ".ber", 4))
	{
		write(2, "Error!\n Wrong file extension", 28);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	window_size(&data, argv);
	check_filename(argv[1]);
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
		calloc_failure("Error\ncalloc failed\n");
	ft_initializer(&data, &map);
	validate_input(&data, argv, argc);
	check_path(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("Error\nprogram initialization failed\n");
		exit(EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.size_x,
			data.size_y, "By Simon Zerisenay");
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	perror("Error\nProgramme failed to loop\n");
	exit(EXIT_FAILURE);
}




/*{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "Hello :)");
	if (!win_ptr)
		return (free(mlx_ptr), 1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free (mlx_ptr);
	return (0);
}