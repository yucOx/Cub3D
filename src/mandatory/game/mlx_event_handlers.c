/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaydin < mehaydin@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:44:23 by mehaydin          #+#    #+#             */
/*   Updated: 2024/01/15 02:52:28 by mehaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy_handler(t_cub3d *cub3d)
{
	free_cub3d(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keydown_handler(int key, t_cub3d *cub3d)
{
	if (key == KEY_ESC)
		destroy_handler(cub3d);
	else if (key == KEY_W)
		cub3d->game->keys.w = 1;
	else if (key == KEY_S)
		cub3d->game->keys.s = 1;
	else if (key == KEY_A)
		cub3d->game->keys.a = 1;
	else if (key == KEY_D)
		cub3d->game->keys.d = 1;
	else if (key == KEY_LEFT)
		cub3d->game->keys.left = 1;
	else if (key == KEY_RIGHT)
		cub3d->game->keys.right = 1;
	return (0);
}

int	keyup_handler(int key, t_cub3d *cub3d)
{
	if (key == KEY_W)
		cub3d->game->keys.w = 0;
	else if (key == KEY_S)
		cub3d->game->keys.s = 0;
	else if (key == KEY_A)
		cub3d->game->keys.a = 0;
	else if (key == KEY_D)
		cub3d->game->keys.d = 0;
	else if (key == KEY_LEFT)
		cub3d->game->keys.left = 0;
	else if (key == KEY_RIGHT)
		cub3d->game->keys.right = 0;
	return (0);
}
