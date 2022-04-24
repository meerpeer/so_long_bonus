/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 17:13:45 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/24 16:43:30 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_playerlocation(t_player *player)
{
	player->position.x = player->image->instances[0].x / SIZE;
	player->position.y = player->image->instances[0].y / SIZE;
}

int	create_player_image(void *mlx, t_player *player, int x, int y)
{
	ft_printf("trying to create player\n");
	player->image = create_img_at_pos(mlx, player->sprite_idle, 0, 0);
	player->image->instances[0].y = SIZE * y;
	player->image->instances[0].x = SIZE * x;
	player->image->instances[0].z = 2;
	set_playerlocation(player);
	return (0);
}

int	move_player(t_player *player, t_direction direction)
{
	if (direction == NORTH)
		player->image->instances[0].y -= SIZE;
	if (direction == WEST)
		player->image->instances[0].x -= SIZE;
	if (direction == SOUTH)
		player->image->instances[0].y += SIZE;
	if (direction == EAST)
		player->image->instances[0].x += SIZE;
	set_playerlocation(player);
	return (0);
}

t_bool	check_can_move(t_player *player, t_direction direction, char **map)
{
	int	x;
	int	y;

	x = player->position.x;
	y = player->position.y;
	if (direction == NORTH)
		y -= 1;
	if (direction == WEST)
		x -= 1;
	if (direction == SOUTH)
		y += 1;
	if (direction == EAST)
		x += 1;
	if (x < 1 || y < 1 || map[y][x] == '1')
		return (FALSE);
	return (TRUE);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	t_direction	direction;

	game = param;
	direction = NONE;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			direction = NORTH;
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			direction = WEST;
		else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			direction = SOUTH;
		else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			direction = EAST;
		else if (keydata.key == MLX_KEY_ESCAPE)
			exit(0);
		if (check_can_move(game->player, direction, game->map))
		{
			move_player(game->player, direction);
			update_gamestate(game);
		}
		if (keydata.key == MLX_KEY_Q)
			mlx_draw_texture(game->img_exit, game->sprites->exit_open, 0, 0);
	}
}
