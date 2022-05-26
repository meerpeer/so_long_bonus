/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_error.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 15:14:12 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/26 12:32:41 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_error(char *str)
{
	ft_printf("ERROR\n%s\n", str);
	exit(0);
	return ;
}

void	check_input_file_error(int argc, char **argv)
{
	if (argc != 2)
		map_error("Incorrect number off arguments");
	if (!ft_strrncmp (argv[1], ".ber", 4))
		map_error("Incorrect file type");
}

void	check_layout_error(t_layout *layout)
{
	if (layout->wrong_shape)
		map_error("Not a rectangle");
	if (layout->wall_incomplete)
		map_error("Walls not closed");
	if (layout->n_players == 0)
		map_error("No starting point detected");
	if (layout->n_players > 1)
		map_error("Too many starting points detected");
	if (layout->n_collects < 1)
		map_error("Not enough collectibles");
	if (layout->n_exits == 0)
		map_error("No exit detected");
	if (layout->n_exits > 1)
		map_error("Too many exits detected");
	if (layout->has_wrong_char)
		map_error("Wrong character detected");
	return ;
}
