/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pawn.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 17:13:45 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/19 17:48:37 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_pawn_location(t_2dVector *position, mlx_instance_t *instance)
{
	position->x = instance->x / SIZE;
	position->y = instance->y / SIZE;
}

int	move_pawn(t_pawn *pawn, t_direction direction)
{
	if (direction == NORTH)
		pawn->image->instances[0].y -= SIZE;
	if (direction == WEST)
		pawn->image->instances[0].x -= SIZE;
	if (direction == SOUTH)
		pawn->image->instances[0].y += SIZE;
	if (direction == EAST)
		pawn->image->instances[0].x += SIZE;
	set_pawn_location(&pawn->position, &pawn->image->instances[0]);
	return (0);
}

t_bool	can_pawn_move(t_pawn *pawn, t_direction direction, char **map)
{
	int	x;
	int	y;

	x = pawn->position.x;
	y = pawn->position.y;
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
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
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
		if (can_pawn_move(&game->player, direction, game->map) && direction)
		{
			move_pawn(&game->player, direction);
			update_gamestate(game);
		}
	}
}
