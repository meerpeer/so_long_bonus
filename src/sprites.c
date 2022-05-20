/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 11:47:34 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/20 17:32:06 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_collect_sprites(t_sprites *sprites)
{
	int	i;

	sprites->collects = ft_calloc(8, sizeof(mlx_texture_t));
	sprites->collects[0] = mlx_load_png("sprites/keys/key1.png");
	sprites->collects[1] = mlx_load_png("sprites/keys/key2.png");
	sprites->collects[2] = mlx_load_png("sprites/keys/key3.png");
	sprites->collects[3] = mlx_load_png("sprites/keys/key4.png");
	sprites->collects[4] = mlx_load_png("sprites/keys/key5.png");
	sprites->collects[5] = mlx_load_png("sprites/keys/key6.png");
	sprites->collects[6] = mlx_load_png("sprites/keys/key7.png");
	sprites->collects[7] = mlx_load_png("sprites/keys/key8.png");
	i = 0;
	while (sprites->collects[i])
		i++;
	if (i < 8)
		exit(0);
}

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
		|| !sprites->exit_close
		|| !sprites->exit_open
		|| !enemy_data->idle)
		exit(0);
}

int	*get_sprites(t_sprites *sprites, t_animdata *player_data,
	t_animdata *enemy_data)
{
	sprites->floor = mlx_load_png("sprites/32floor2.png");
	sprites->wall = mlx_load_png("sprites/32wall.png");
	sprites->exit_close = mlx_load_png("sprites/32door_closed.png");
	sprites->exit_open = mlx_load_png("sprites/32door_open.png");
	player_data->idle = mlx_load_png("sprites/player_right.png");
	player_data->move_right = mlx_load_png("sprites/player_right.png");
	player_data->move_left = mlx_load_png("sprites/player_left.png");
	enemy_data->idle = mlx_load_png("sprites/enemy_idle.png");
	enemy_data->move_right = mlx_load_png("sprites/enemy_right.png");
	enemy_data->move_left = mlx_load_png("sprites/enemy_left.png");
	get_collect_sprites(sprites);
	check_sprite_allocation(sprites, player_data, enemy_data);
	return (0);
}
