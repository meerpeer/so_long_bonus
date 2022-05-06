/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   show_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 11:37:46 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/06 16:38:38 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*create_img_at_pos(void *mlx, mlx_texture_t *texture, int x, int y)
{
	mlx_image_t	*image;

	printf("showing exit\n");
	image = mlx_new_image(mlx, SIZE, SIZE);
	mlx_draw_texture(image, texture, 0, 0);
	mlx_image_to_window(mlx, image, SIZE * x, SIZE * y);
	return (image);
}

mlx_image_t	*create_background_image(void *mlx, int width, int height)
{
	mlx_image_t	*img_background;

	img_background = mlx_new_image(mlx, SIZE * width, SIZE * height);
	mlx_image_to_window(mlx, img_background, 0, 0);
	return (img_background);
}

int	draw_background_tile(mlx_image_t *img, t_2dVector map_location,
	t_sprites sprites, char **map)
{
	int	x;
	int	y;

	x = map_location.x;
	y = map_location.y;
	mlx_draw_texture(img, sprites.floor, x * SIZE, y * SIZE);
	if (map[y][x] == '1')
		mlx_draw_texture(img, sprites.wall, x * SIZE, y * SIZE);
	return (0);
}

int	show_map(char **map, t_game *game)
{
	t_2dVector	location;

	game->img_background = create_background_image(game->mlx,
			game->map_width, game->map_height);
	location.y = 0;
	while (map[location.y])
	{
		location.x = 0;
		while (map[location.y][location.x])
		{
			draw_background_tile(game->img_background, location,
				game->sprites, map);
			if (map[location.y][location.x] == 'C')
				create_collectable(game->mlx, &game->collectables,
					location, game->sprites.collect);
			if (map[location.y][location.x] == 'E')
				game->img_exit = create_img_at_pos(game->mlx,
						game->sprites.exit_close, location.x, location.y);
			if (map[location.y][location.x] == 'P')
				create_player_image(game->mlx, &game->player,
					location.x, location.y);
			location.x++;
		}
		location.y++;
	}
	return (0);
}
