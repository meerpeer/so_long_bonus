/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 11:47:34 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/20 14:16:25 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_anim(t_animdata animdata, t_pawn pawn)
{
	if (pawn.move_direction == WEST || pawn.move_direction == SOUTH)
		mlx_draw_texture(pawn.image, animdata.move_left, 0, 0);
	else if (pawn.move_direction == EAST || pawn.move_direction == NORTH)
		mlx_draw_texture(pawn.image, animdata.move_right, 0, 0);
	return ;
}

void	check_sprite_allocation(t_sprites *sprites, t_animdata *player_data,
	t_animdata *enemy_data)
{
	if (!sprites->floor
		|| !sprites->wall
		|| !player_data->idle
		|| !sprites->collect
		|| !sprites->exit_close
		|| !sprites->exit_open
		|| !enemy_data->idle)
		exit(0);
}

int	*get_sprites(t_sprites *sprites, t_animdata *player_data,
	t_animdata *enemy_data)
{
	sprites->floor = mlx_load_png("sprites/32floor.png");
	sprites->wall = mlx_load_png("sprites/32wall.png");
	sprites->collect = mlx_load_png("sprites/32collect.png");
	sprites->exit_close = mlx_load_png("sprites/32door_closed.png");
	sprites->exit_open = mlx_load_png("sprites/32door_open.png");
	player_data->idle = mlx_load_png("sprites/player_right.png");
	player_data->move_right = mlx_load_png("sprites/player_right.png");
	player_data->move_left = mlx_load_png("sprites/player_left.png");
	enemy_data->idle = mlx_load_png("sprites/enemy_idle.png");
	enemy_data->move_right = mlx_load_png("sprites/enemy_right.png");
	enemy_data->move_left = mlx_load_png("sprites/enemy_left.png");
	check_sprite_allocation(sprites, player_data, enemy_data);
	return (0);
}
