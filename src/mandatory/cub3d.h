/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaydin < mehaydin@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:45:24 by mehaydin          #+#    #+#             */
/*   Updated: 2024/01/15 02:52:28 by mehaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MOVE_SPEED 0.075
# define TURN_SPEED 0.05

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17

# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# endif

# include <stdlib.h>

typedef struct s_xpm_files
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;

	int		north_count;
	int		south_count;
	int		west_count;
	int		east_count;
}			t_xpm_files;

typedef struct s_color
{
	char	*red_string;
	char	*green_string;
	char	*blue_string;
	char	*string;

	int		count;
	int		red;
	int		green;
	int		blue;
}			t_color;

typedef struct s_map
{
	char	**text;
	int		starting_line;
	int		row_count;
	int		col_count;

	int		player_count;
	int		player_row;
	int		player_col;
}			t_map;

typedef struct s_config
{
	int			argument_count;
	char		*filename;

	char		**text;
	int			total_line_count;
	int			full_line_count;
	int			empty_line_count;

	t_xpm_files	*xpm_files;
	t_color		*floor_color;
	t_color		*ceiling_color;
	t_map		*map;
}				t_config;

typedef struct s_vector_double
{
	double	x;
	double	y;
}			t_vector_double;

typedef struct s_vector_int
{
	int	x;
	int	y;
}		t_vector_int;

typedef struct s_player
{
	t_vector_double	position;
	t_vector_double	direction;
	t_vector_double	camera_plane;
}				t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}		t_keys;

typedef struct s_mlx_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_mlx_image;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_mlx_image	*screen;
	t_mlx_image	*north_image;
	t_mlx_image	*south_image;
	t_mlx_image	*west_image;
	t_mlx_image	*east_image;
	int			floor_rgb;
	int			ceiling_rgb;
	t_keys		keys;
	t_player	*player;
}				t_game;

typedef struct s_cub3d
{
	t_config	*config;
	t_game		*game;
}				t_cub3d;

typedef struct s_screen
{
	long	wall_height;
	int		wall_start_point;
	int		wall_end_point;
	int		hit_point_wall_texture;
	double	texture_offset_y;
	double	texture_pixel_ratio;
}			t_screen;

typedef struct s_ray
{
	t_vector_int	map_position;
	t_vector_double	real_position;
	t_vector_double	direction;
	t_vector_double	side_dist;
	t_vector_double	next_hit_dist;
	t_vector_int	map_step;
	int				hit_wall;
	char			hit_wall_side;
	double			view_of_wall;
	double			hit_point_wall;
	t_screen		screen;
}					t_ray;

void	init_config(t_cub3d *cub3d, int argument_count, char *filename);
void	free_config(t_cub3d *cub3d);
void	init_xpm_files(t_cub3d *cub3d);
void	free_xpm_files(t_cub3d *cub3d);
void	init_colors(t_cub3d *cub3d);
void	free_colors(t_cub3d *cub3d);
void	init_map(t_cub3d *cub3d);
void	free_map(t_cub3d *cub3d);
void	verify_argument(t_cub3d *cub3d);
void	verify_is_config_blackhole(t_cub3d *cub3d);
void	set_config_line_count(t_cub3d *cub3d);
void	set_config_text(t_cub3d *cub3d);
void	set_elements_count(t_cub3d *cub3d);
void	verify_elements(t_cub3d *cub3d);
void	validate_xpm_files(t_cub3d *cub3d, char *line);
void	validate_floor_color(t_cub3d *cub3d, char *line);
void	validate_ceiling_color(t_cub3d *cub3d, char *line);
void	set_map_text(t_cub3d *cub3d);
char	**create_map_same_row_len(t_cub3d *cub3d);
void	check_map_empty_line(t_cub3d *cub3d);
void	verify_map_characters(t_cub3d *cub3d);
void	verify_map_walls(t_cub3d *cub3d);
void	verify_map_spaces(t_cub3d *cub3d);
void	verify_map(t_cub3d *cub3d);
char	*get_next_line(t_cub3d *cub3d, int fd);
int		is_empty_line(char *line);

void	init_game(t_cub3d *cub3d);
void	free_game(t_cub3d *cub3d);
void	init_mlx(t_cub3d *cub3d);
void	free_mlx(t_cub3d *cub3d);
void	init_screen(t_cub3d *cub3d);
void	free_screen(t_cub3d *cub3d);
void	init_north_mlx_image(t_cub3d *cub3d);
void	init_south_mlx_image(t_cub3d *cub3d);
void	init_west_mlx_image(t_cub3d *cub3d);
void	init_east_mlx_image(t_cub3d *cub3d);
void	init_ceiling_rgb(t_cub3d *cub3d);
void	init_floor_rgb(t_cub3d *cub3d);
void	free_xpm_images(t_cub3d *cub3d);
void	init_player(t_cub3d *cub3d);
void	free_player(t_cub3d *cub3d);

void	ray_properties(t_ray *ray, t_player *player, int x);
void	ray_draw_until_hit_wall(t_ray *ray, t_map *map);
void	ray_wall_properties(t_ray *ray, t_player *player);
void	ray_texture_properties(t_ray *ray);
void	ray_fill_screen(t_ray *ray, t_game *game, int x);
void	raycasting(t_cub3d *cub3d);

void	player_move_up(t_map *map, t_player *player);
void	player_move_down(t_map *map, t_player *player);
void	player_move_left(t_map *map, t_player *player);
void	player_move_right(t_map *map, t_player *player);
void	player_turn_left(t_player *player);
void	player_turn_right(t_player *player);

size_t	get_image_color(t_mlx_image *image, int x, int y);
void	put_pixel_to_mlx_image(t_mlx_image *image, int x, int y, int color);
int		destroy_handler(t_cub3d *cub3d);
int		keydown_handler(int key, t_cub3d *cub3d);
int		keyup_handler(int key, t_cub3d *cub3d);
int		loop_handler(t_cub3d *cub3d);

t_cub3d	*init_cub3d(int argument_count, char *filename);
void	free_cub3d(t_cub3d *cub3d);
void	print_error(t_cub3d *cub3d, char *message);

#endif