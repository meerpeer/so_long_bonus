/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 17:13:45 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/10 18:09:34 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_playerlocation(t_game *game)
{
	game->playerpos.x = game->img_player->instances[0].x / SIZE;
	game->playerpos.y = game->img_player->instances[0].y / SIZE;
	//printf("player pos= %i,%i\n", game->playerpos.y, game->playerpos.x);
}

int	create_player_image(t_game *game, int x, int y)
{
	game->img_player = mlx_new_image(game->mlx, SIZE, SIZE);
	mlx_draw_texture(game->img_player, game->sprites->player, 0, 0);
	mlx_image_to_window(game->mlx, game->img_player, 0, 0);
	game->img_player->instances[0].y = SIZE * y;
	game->img_player->instances[0].x = SIZE * x;
	game->img_player->instances[0].z = 2;
	set_playerlocation(game);
	return (0);
}

int	move_player(t_game *game, int direction)
{
	if (direction == NORTH)
		game->img_player->instances[0].y -= SIZE;
	if (direction == WEST)
		game->img_player->instances[0].x -= SIZE;
	if (direction == SOUTH)
		game->img_player->instances[0].y += SIZE;
	if (direction == EAST)
		game->img_player->instances[0].x += SIZE;
	set_playerlocation(game);
	return (0);
}

int	try_move(t_game *game, int direction)
{
	int	x;
	int	y;

	x = game->playerpos.x;
	y = game->playerpos.y;
	if (direction == NORTH)
		y -= 1;
	if (direction == WEST)
		x -= 1;
	if (direction == SOUTH)
		y += 1;
	if (direction == EAST)
		x += 1;
	if (x < 1 || y < 1
		|| x >= game->layout->n_collums || y >= game->layout->n_rows
		|| game->map[y][x] == '1')
		return (0);
	move_player(game, direction);
	return (1);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game				*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			try_move(game, NORTH);
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			try_move(game, WEST);
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			try_move(game, SOUTH);
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			try_move(game, EAST);
		if (keydata.key == MLX_KEY_ESCAPE)
			exit(0);
		if (keydata.key == MLX_KEY_Q)
			mlx_draw_texture(game->img_exit, game->sprites->exit_open, 0, 0);
		try_collect(game);
	}
}
