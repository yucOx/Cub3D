/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaydin < mehaydin@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:43:58 by mehaydin          #+#    #+#             */
/*   Updated: 2024/01/15 02:52:28 by mehaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	character_is_player(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
	{
		return (1);
	}
	return (0);
}

static void	set_player_direction(t_player *player, char player_direction)
{
	if (player_direction == 'N')
	{
		player->direction.y = -1;
		player->camera_plane.x = 0.66;
	}
	else if (player_direction == 'S')
	{
		player->direction.y = 1;
		player->camera_plane.x = -0.66;
	}
	else if (player_direction == 'W')
	{
		player->direction.x = -1;
		player->camera_plane.y = -0.66;
	}
	else if (player_direction == 'E')
	{
		player->direction.x = 1;
		player->camera_plane.y = 0.66;
	}
}

static void	set_player_properties(t_cub3d *cub3d)
{
	t_map	*map;
	int		row;
	int		col;

	map = cub3d->config->map;
	row = 0;
	while (map->text[row] != NULL)
	{
		col = 0;
		while (map->text[row][col] != '\0')
		{
			if (character_is_player(map->text[row][col]))
			{
				cub3d->game->player->position.x = (double)col + 0.5;
				cub3d->game->player->position.y = (double)row + 0.5;
				set_player_direction(cub3d->game->player, map->text[row][col]);
			}
			col++;
		}
		row++;
	}
}
//focus the middle of pixel

void	init_player(t_cub3d *cub3d)
{
	cub3d->game->player = malloc(sizeof(t_player));
	if (cub3d->game->player == NULL)
		print_error(cub3d, "player malloc error.");
	cub3d->game->player->position.x = 0;
	cub3d->game->player->position.y = 0;
	cub3d->game->player->direction.x = 0;
	cub3d->game->player->direction.y = 0;
	cub3d->game->player->camera_plane.x = 0;
	cub3d->game->player->camera_plane.y = 0;
	set_player_properties(cub3d);
}

void	free_player(t_cub3d *cub3d)
{
	if (cub3d->game->player == NULL)
		return ;
	free(cub3d->game->player);
}
