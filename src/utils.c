/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 17:45:17 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/18 15:05:26 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_2dVector	correct_location(char **map, int starty, int startx)
{
	t_2dVector	corrected_location;
	int			width;

	width = ft_strlen(map[0]);
	if (startx >= width)
	{
		corrected_location.x = 0;
		corrected_location.y = starty + 1;
	}
	else
	{
		corrected_location.x = startx;
		corrected_location.y = starty;
	}
	return (corrected_location);
}

t_2dVector	get_next_tiletype_location(char **map, char type, int starty,
	int startx)
{
	t_2dVector	location;

	location = correct_location(map, starty, startx);
	while (map[location.y])
	{
		while (map[location.y][location.x])
		{
			if (map[location.y][location.x] == type)
				return (location);
			location.x++;
		}
		location.x = 0;
		location.y++;
	}
	location.x = -1;
	location.y = -1;
	return (location);
}
