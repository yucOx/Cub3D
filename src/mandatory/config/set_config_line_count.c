/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config_line_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaydin < mehaydin@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:40:24 by mehaydin          #+#    #+#             */
/*   Updated: 2024/01/15 02:52:28 by mehaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

static void	clear_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		line[i] = '\0';
		i++;
	}
}

static void	handle_line(t_config *config, char *line, int readed_byte, int *i)
{
	if (line[*i] == '\n' || readed_byte == 0)
	{
		config->total_line_count++;
		line[*i + 1] = '\0';
		if (!is_empty_line(line))
		{
			config->full_line_count++;
			if (config->full_line_count == 7)
				config->map->starting_line = config->total_line_count;
		}
		else
			config->empty_line_count++;
		clear_line(line);
		*i = -1;
	}
}

void	set_config_line_count(t_cub3d *cub3d)
{
	char	line[1024];
	char	character;
	int		readed_byte;
	int		i;
	int		fd;

	character = '\0';
	readed_byte = 1;
	i = 0;
	fd = open(cub3d->config->filename, O_RDONLY);
	if (fd == -1)
		print_error(cub3d, "An error occurred while opening the map file.");
	while (readed_byte > 0)
	{
		readed_byte = read(fd, &character, 1);
		if (readed_byte == -1)
			print_error(cub3d, "The map file could not be read.");
		line[i] = character;
		handle_line(cub3d->config, line, readed_byte, &i);
		i++;
	}
	close(fd);
	if (cub3d->config->full_line_count < 9)
		print_error(cub3d, "There must be at least 9 text \
		in the configuration file. (4 texture, 2 color, min 3 for map)");
}
