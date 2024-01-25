/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_floor_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaydin < mehaydin@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:42:25 by mehaydin          #+#    #+#             */
/*   Updated: 2024/01/15 02:52:28 by mehaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

static void	validate_comma(t_cub3d *cub3d)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (cub3d->config->floor_color->string[i] != '\0')
	{
		if (cub3d->config->floor_color->string[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		print_error(cub3d, "F take a value in RGB format. \
		The RGB value consists of 3 parts separated by 2 commas.");
}

static void	validate_red_color(t_cub3d *cub3d)
{
	char	*red_string;
	int		red;
	int		red_len;
	int		i;

	red_string = cub3d->config->floor_color->red_string;
	red_len = ft_strlen(red_string);
	if (red_len == 0)
		print_error(cub3d, "Red color of F can't be empty.");
	if (red_len > 3)
		print_error(cub3d, "Red color of F must be between \
		1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < red_len)
	{
		if (!ft_is_digit(red_string[i]))
			print_error(cub3d, "Red color of F must \
			consist of digit only. (0 - 9)");
		i++;
	}
	red = ft_atoi(red_string);
	if (red < 0 || red > 255)
		print_error(cub3d, "Red color of F must be a value between 0-255.");
	cub3d->config->floor_color->red = red;
}

static void	validate_green_color(t_cub3d *cub3d)
{
	char	*green_string;
	int		green;
	int		green_len;
	int		i;

	green_string = cub3d->config->floor_color->green_string;
	green_len = ft_strlen(green_string);
	if (green_len == 0)
		print_error(cub3d, "Green color of F can't be empty.");
	if (green_len > 3)
		print_error(cub3d, "Green color of F must be between \
		1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < green_len)
	{
		if (!ft_is_digit(green_string[i]))
			print_error(cub3d, "Green color of F must \
			consist of digit only. (0 - 9)");
		i++;
	}
	green = ft_atoi(green_string);
	if (green < 0 || green > 255)
		print_error(cub3d, "Green color of F must be a value between 0-255.");
	cub3d->config->floor_color->green = green;
}

static void	validate_blue_color(t_cub3d *cub3d)
{
	char	*blue_string;
	int		blue;
	int		blue_len;
	int		i;

	blue_string = cub3d->config->floor_color->blue_string;
	blue_len = ft_strlen(blue_string);
	if (blue_len == 0)
		print_error(cub3d, "Blue color of F can't be empty.");
	if (blue_len > 3)
		print_error(cub3d, "Blue color of F must be between \
		1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < blue_len)
	{
		if (!ft_is_digit(blue_string[i]))
			print_error(cub3d, "Blue color of F must \
			consist of digit only. (0 - 9)");
		i++;
	}
	blue = ft_atoi(blue_string);
	if (blue < 0 || blue > 255)
		print_error(cub3d, "Blue color of F must be a value between 0-255.");
	cub3d->config->floor_color->blue = blue;
}

void	validate_floor_color(t_cub3d *cub3d, char *line)
{
	char	**rgb;

	rgb = NULL;
	if (line[0] == 'F')
	{
		cub3d->config->floor_color->string = ft_strtrim_start(line + 1, " \t");
		if (*cub3d->config->floor_color->string == '\0')
			print_error(cub3d, "F element cant' be empty.");
		validate_comma(cub3d);
		rgb = ft_split(cub3d->config->floor_color->string, ',');
		cub3d->config->floor_color->red_string = ft_strdup(rgb[0]);
		cub3d->config->floor_color->green_string = ft_strdup(rgb[1]);
		cub3d->config->floor_color->blue_string = ft_strdup(rgb[2]);
		free_double_pointer(rgb);
		validate_red_color(cub3d);
		validate_green_color(cub3d);
		validate_blue_color(cub3d);
	}
}
