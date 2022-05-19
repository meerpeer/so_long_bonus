/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 13:25:50 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/19 18:05:41 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	switch_direction(t_direction *direction, t_pawn *pawn)
{
	//update anim
	ft_printf("direction = %i\n", *direction);
	if (*direction == NORTH)
		*direction = SOUTH;
	else if (*direction == SOUTH)
	{
		ft_printf("direction north =%i\n", NORTH);
		*direction = NORTH;
	}
	else if (*direction == EAST)
		*direction = WEST;
	else
		*direction = EAST;
	ft_printf("changed to = %i\n\n", *direction);
}

void	move_enemies(t_pawn **enemies, char **map)
{
	t_pawn	*enemy_to_move;
	t_bool	move_possible;

	enemy_to_move = *enemies;
	while (enemy_to_move)
	{
		if (can_pawn_move(enemy_to_move, enemy_to_move->move_direction,
				map))
			move_pawn(enemy_to_move, enemy_to_move->move_direction);
		else
			switch_direction(&enemy_to_move->move_direction, enemy_to_move);
		enemy_to_move = enemy_to_move->next_pawn;
	}
}

void	check_enemy_contact(t_pawn *enemies, t_2dVector playerpos)
{
	t_pawn		*enemy_to_check;
	t_2dVector	enemypos;

	enemy_to_check = enemies;
	while (enemy_to_check)
	{
		enemypos = enemy_to_check->position;
		if (enemypos.x == playerpos.x && enemypos.y == playerpos.y)
		{
		//	system("leaks so_long");
			exit(0);
		}
		enemy_to_check = enemy_to_check->next_pawn;
	}
	return ;
}


