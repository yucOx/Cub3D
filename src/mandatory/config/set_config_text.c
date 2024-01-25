/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaydin < mehaydin@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:40:31 by mehaydin          #+#    #+#             */
/*   Updated: 2024/01/15 02:52:28 by mehaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

void	set_config_text(t_cub3d *cub3d)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(cub3d->config->filename, O_RDONLY);
	if (fd == -1)
		print_error(cub3d, "An error occurred while opening the map file.");
	cub3d->config->text = malloc(
			sizeof(char *) * (cub3d->config->full_line_count + 1));
	if (cub3d->config->text == NULL)
		print_error(cub3d, "config->text malloc error.");
	cub3d->config->text[cub3d->config->full_line_count] = NULL;
	i = 0;
	while (i < cub3d->config->full_line_count)
	{
		line = get_next_line(cub3d, fd);
		if (!is_empty_line(line))
		{
			cub3d->config->text[i] = line;
			i++;
		}
		else
			free(line);
	}
	close(fd);
}
