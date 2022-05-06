/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 17:45:17 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/06 17:50:32 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_2dVector	get_next_tiletype_location(char **map, char type, int starty,
	int startx)
{
	t_2dVector	location;

	location.y = starty;
	location.x = startx;
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
