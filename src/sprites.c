/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 11:47:34 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/19 16:39:56 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	sprites->floor = mlx_load_png("sprites/floor_1.png");
	sprites->wall = mlx_load_png("sprites/wall_mid.png");
	player_data->idle = mlx_load_png("sprites/skelet_idle.png");
	sprites->collect = mlx_load_png("sprites/key.png");
	sprites->exit_close = mlx_load_png("sprites/exit_close.png");
	sprites->exit_open = mlx_load_png("sprites/exit_open.png");
	enemy_data->idle = mlx_load_png("sprites/skelet_idle.png");
	check_sprite_allocation(sprites, player_data, enemy_data);
	return (0);
}
