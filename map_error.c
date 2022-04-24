/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_error.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 15:14:12 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/24 14:08:37 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *str, char **map)
{
	// maybe check if this actually frees a 2d array
	if (map)
		free(map);
	ft_printf("ERROR\n%s\n", str);
	exit(0);
	return ;
}

void	check_input_file_error(int argc, char **argv)
{
	if (argc != 2)
		map_error("Incorrect number off files presented", NULL);
	if (!ft_strrncmp (argv[1], ".ber", 4))
		map_error("Incorrect file type", NULL);
}

void	check_layout_error(char **map)
{
	t_layout	*layout;

	layout = get_layout(map);
	if (!layout->is_rectangle)
		map_error("Not a rectangle", map);
	if (!layout->is_wall)
		map_error("Walls not closed", map);
	if (layout->n_players == 0)
		map_error("No player detected", map);
	if (layout->n_players > 1)
		map_error("Too many players detected", map);
	if (layout->n_collects < 1)
		map_error("Not enough collectibles", map);
	if (layout->n_exits == 0)
		map_error("No exit detected", map);
	if (layout->n_exits > 1)
		map_error("Too many exits detected", map);
	if (layout->n_exits > 1)
		map_error("Too many exits detected", map);
	if (layout->has_wrong_char)
		map_error("Wrong character detected", map);
	return ;
}
