/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 11:47:34 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/18 12:45:41 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	*get_sprites(t_sprites *sprites, t_player *player)
{
	int			size;

	size = SIZE;
	sprites->floor = mlx_load_png("sprites/floor_1.png");
	sprites->wall = mlx_load_png("sprites/wall_mid.png");
	player->sprite_idle = mlx_load_png("sprites/skelet_idle_anim_f0.png");
	sprites->collect = mlx_load_png("sprites/key.png");
	sprites->exit_close = mlx_load_png("sprites/exit_close.png");
	sprites->exit_open = mlx_load_png("sprites/exit_open.png");
	return (0);
}
