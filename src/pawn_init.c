/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pawn_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 17:09:02 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/20 16:44:08 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_pawn_at_start(t_pawn *pawn, int x, int y)
{
	pawn->image->instances[0].y = SIZE * y;
	pawn->image->instances[0].x = SIZE * x;
	set_pawn_location(&pawn->position, &pawn->image->instances[0]);
}

void	spawn_player(mlx_t *mlx, char **map, t_pawn *player,
	t_animdata animdata)
{
	t_2dVector	location;

	location = get_next_tiletype_location(map, 'P', 0, 0);
	player->image = create_img_at_pos(mlx, animdata.idle, location);
	player->next_pawn = NULL;
	put_pawn_at_start(player, location.x, location.y);
	return ;
}

void	create_new_enemy(mlx_t *mlx, t_pawn **enemies, t_animdata animdata,
	t_2dVector pos)
{
	t_pawn	*new_enemy;
	t_pawn	*last_enemy;

	new_enemy = ft_calloc(1, sizeof(struct s_pawn));
	new_enemy->image = mlx_new_image(mlx, SIZE, SIZE);
	if (!new_enemy->image)
		exit(0);
	mlx_draw_texture(new_enemy->image, animdata.idle, 0, 0);
	mlx_image_to_window(mlx, new_enemy->image, 0, 0);
	put_pawn_at_start(new_enemy, pos.x, pos.y);
	if (*enemies)
	{
		last_enemy = *enemies;
		*enemies = new_enemy;
		new_enemy->next_pawn = last_enemy;
	}
	else
		*enemies = new_enemy;
}

void	spawn_enemies(mlx_t *mlx, char **map, t_pawn **enemies,
	t_animdata animdata)
{
	t_2dVector	last_enemy_location;

	last_enemy_location = get_next_tiletype_location(map, 'V', 0, 0);
	while (last_enemy_location.x >= 0)
	{
		create_new_enemy(mlx, enemies, animdata, last_enemy_location);
		enemies[0]->move_direction = SOUTH;
		if (can_pawn_move(*enemies, EAST, map)
			|| can_pawn_move(*enemies, WEST, map))
			enemies[0]->move_direction = EAST;
		last_enemy_location = get_next_tiletype_location(map, 'V',
				last_enemy_location.y, last_enemy_location.x + 1);
	}
}
