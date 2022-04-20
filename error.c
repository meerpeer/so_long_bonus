/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 15:14:12 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/03/24 11:14:03 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_error(char *str, char *map_lines)
{
	if (map_lines)
		free(map_lines);
	ft_printf("ERROR\n%s\n", str);
	exit(0);
	return (0);
}

int	check_layout_error(t_layout *layout, char *map_lines)
{
	if (layout->rect_error)
		map_error("Not a rectangle", map_lines);
	if (layout->wall_error)
		map_error("Walls not closed", map_lines);
	if (layout->n_players == 0)
		map_error("No player detected", map_lines);
	if (layout->n_players > 1)
		map_error("Too many players detected", map_lines);
	if (layout->n_collects < 1)
		map_error("Not enough collectibles", map_lines);
	if (layout->n_exits == 0)
		map_error("No exit detected", map_lines);
	if (layout->n_exits > 1)
		map_error("Too many exits detected", map_lines);
	if (layout->n_exits > 1)
		map_error("Too many exits detected", map_lines);
	if (layout->wrong_char_error > 0)
		map_error("Wrong character detected", map_lines);
	return (0);
}
