/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:20:08 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/10 17:41:34 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"

// Size of tiles
# define SIZE 16 

//# define S_SIZE 16

// Define tileset
//# define FLOORTILE =

// Keyscodes for events
# define KEY_W 87
# define KEY_A 0
# define KEY_S 1
# define KEY_D 
# define KEY_ESC 256

// Directions
# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

// layout values
typedef struct s_layout {
	int	n_players;
	int	n_exits;
	int	n_collects;
	int	n_rows;
	int	n_collums;
	int	rect_error;
	int	wall_error;
	int	wrong_char_error;
}				t_layout;

typedef struct s_playerpos {
	int	x;
	int	y;
}				t_playerpos;

// sprites
typedef struct s_sprites {
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*screen_img;
	mlx_texture_t	*player;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit_close;
	mlx_texture_t	*exit_open;
}				t_sprites;

// collectable variables
typedef struct s_collect {
	int			x;
	int			y;
	mlx_image_t	*img_collect;
	void		*next;
}				t_collect;

//directions
enum	e_direction
{
	north,
	east,
	south,
	west,
};

// game variables
typedef struct s_game {
	void		*mlx;
	t_sprites	*sprites;
	char		**map;
	int			collected;
	t_collect	*collectables;
	t_layout	*layout;
	t_playerpos	playerpos;
	mlx_image_t	*img_player;
	mlx_image_t	*img_background;
	mlx_image_t	*img_collect;
	mlx_image_t	*img_exit;
	int			test;
}				t_game;

char		**read_map(int argc, char *argv[], char **map, t_layout	*layout);
int			map_error(char *str, char *map_lines);
int			check_layout_error(t_layout *layout, char *map_lines);
char		*append_str(char *base, char *add);
int			start_game(char **map, t_layout *layout);
void		key_hook(mlx_key_data_t keydata, void *param);
void		tick(void *param);
t_layout	create_layout(void);
void		set_playerlocation(t_game *game);
int			show_map(char **map, t_game *game);
int			*get_sprites(t_game *game);
int			create_player_image(t_game *game, int x, int y);
int			create_collectable(t_game *game, int x, int y);
int			try_collect(t_game *game);
void		lstcollect_addback(t_collect **lst, t_collect *new);
t_collect	*new_lstcollect(mlx_image_t *img, int x, int y);

#endif