/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaydin < mehaydin@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:41:58 by mehaydin          #+#    #+#             */
/*   Updated: 2024/01/15 02:52:28 by mehaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_colors(t_cub3d *cub3d)
{
	cub3d->config->floor_color = malloc(sizeof(t_color));
	if (cub3d->config->floor_color == NULL)
		print_error(cub3d, "floor_color malloc error.");
	cub3d->config->ceiling_color = malloc(sizeof(t_color));
	if (cub3d->config->ceiling_color == NULL)
		print_error(cub3d, "ceiling_color malloc error.");
	cub3d->config->floor_color->red = -1;
	cub3d->config->floor_color->green = -1;
	cub3d->config->floor_color->blue = -1;
	cub3d->config->floor_color->count = 0;
	cub3d->config->floor_color->string = NULL;
	cub3d->config->floor_color->red_string = NULL;
	cub3d->config->floor_color->green_string = NULL;
	cub3d->config->floor_color->blue_string = NULL;
	cub3d->config->ceiling_color->red = -1;
	cub3d->config->ceiling_color->green = -1;
	cub3d->config->ceiling_color->blue = -1;
	cub3d->config->ceiling_color->count = 0;
	cub3d->config->ceiling_color->string = NULL;
	cub3d->config->ceiling_color->red_string = NULL;
	cub3d->config->ceiling_color->green_string = NULL;
	cub3d->config->ceiling_color->blue_string = NULL;
}

void	free_colors(t_cub3d *cub3d)
{
	if (cub3d->config->floor_color != NULL)
	{
		if (cub3d->config->floor_color->string != NULL)
			free(cub3d->config->floor_color->string);
		if (cub3d->config->floor_color->red_string != NULL)
			free(cub3d->config->floor_color->red_string);
		if (cub3d->config->floor_color->green_string != NULL)
			free(cub3d->config->floor_color->green_string);
		if (cub3d->config->floor_color->blue_string != NULL)
			free(cub3d->config->floor_color->blue_string);
		free(cub3d->config->floor_color);
	}
	if (cub3d->config->ceiling_color != NULL)
	{
		if (cub3d->config->ceiling_color->string != NULL)
			free(cub3d->config->ceiling_color->string);
		if (cub3d->config->ceiling_color->red_string != NULL)
			free(cub3d->config->ceiling_color->red_string);
		if (cub3d->config->ceiling_color->green_string != NULL)
			free(cub3d->config->ceiling_color->green_string);
		if (cub3d->config->ceiling_color->blue_string != NULL)
			free(cub3d->config->ceiling_color->blue_string);
		free(cub3d->config->ceiling_color);
	}
}
