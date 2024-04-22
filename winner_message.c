/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:34:59 by taquino-          #+#    #+#             */
/*   Updated: 2024/04/22 12:34:59 by taquino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	winner(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	printf("-----------------------------------------------\n");
	printf("|    🎉🎉🎉  Congratulations!!!!!  🎉🎉🎉     |\n");
	printf("|    You found all collectibles and exit.     |\n");
	printf("|        ✓✓✓✓✓✓✓✓ You won! ✓✓✓✓✓✓✓✓           |\n");
	printf("|     Is %d moves the best you can do?         |\n", data->counter);
	printf("-----------------------------------------------\n");
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
