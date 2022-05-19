/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 17:13:45 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/19 13:20:48 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_playerlocation(t_playerpos *position, mlx_instance_t *instance)
{
	position->x = instance->x / SIZE;
	position->y = instance->y / SIZE;
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
	set_playerlocation(&player->position, &player->image->instances[0]);
	return (0);
}

t_bool	can_player_move(t_player *player, t_direction direction, char **map)
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
		if (can_player_move(&game->player, direction, game->map) && direction)
		{
			move_player(&game->player, direction);
			update_gamestate(game);
		}
	}
}
