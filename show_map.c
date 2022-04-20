/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   show_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 11:37:46 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/20 08:43:26 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_exit(t_game *game, int x, int y)
{
	printf("showing exit\n");
	game->img_exit = mlx_new_image(game->mlx, SIZE, SIZE);
	mlx_draw_texture(game->img_exit, game->sprites->exit_close, 0, 0);
	mlx_image_to_window(game->mlx, game->img_exit, SIZE * x, SIZE * y);
	return (0);
}

int	create_background_image(t_game *game)
{
	game->img_background = mlx_new_image(game->mlx,
			SIZE * game->layout->n_collums, SIZE * game->layout->n_rows);
	mlx_image_to_window(game->mlx, game->img_background, 0, 0);
	return (0);
}

int	draw_background(t_game *game, int x, int y)
{
	mlx_draw_texture(game->img_background, game->sprites->floor,
		x * SIZE, y * SIZE);
	if (game->map[y][x] == '1')
		mlx_draw_texture(game->img_background, game->sprites->wall,
			x * SIZE, y * SIZE);
	return (0);
}

int	show_map(char **map, t_game *game)
{
	int	x;
	int	y;

	create_background_image(game);
	game->collected = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			draw_background(game, x, y);
			if (map[y][x] == 'C')
				create_collectable(game, x, y);
			if (map[y][x] == 'E')
				create_exit(game, x, y);
			if (map[y][x] == 'P')
				create_player_image(game, x, y);
			x++;
		}
		y++;
	}
	set_playerlocation(game);
	return (0);
}
