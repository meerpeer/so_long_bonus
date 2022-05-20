/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collect_spawn.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 16:56:53 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/20 15:14:14 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_collect	*new_lstcollect(mlx_image_t *img, int x, int y)
{
	t_collect	*new_collect;

	new_collect = ft_malloc (sizeof(struct s_collect));
	if (!new_collect)
		return (NULL);
	new_collect->x = x;
	new_collect->y = y;
	new_collect->img_collect = img;
	new_collect->next = NULL;
	return (new_collect);
}

void	lstcollect_addback(t_collect **lst, t_collect *new)
{
	t_collect	*last;

	last = *lst;
	if (*lst)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*lst = new;
}

int	create_collectable(mlx_t *mlx, t_collect **collect_start,
	t_2dVector location, mlx_texture_t *texture)
{
	mlx_image_t	*new_collect_img;

	new_collect_img = mlx_new_image(mlx, SIZE, SIZE);
	if (!new_collect_img)
		exit (0);
	mlx_draw_texture(new_collect_img,
		texture, 0, 0);
	mlx_image_to_window(mlx, new_collect_img,
		SIZE * location.x, SIZE * location.y);
	lstcollect_addback(collect_start,
		new_lstcollect(new_collect_img, location.x, location.y));
	return (0);
}

void	spawn_collectables(mlx_t *mlx, char **map, t_collect **collectables,
	mlx_texture_t *texture)
{
	t_2dVector	location;

	location = get_next_tiletype_location(map, 'C', 0, 0);
	while (location.y >= 0)
	{
		create_collectable(mlx, collectables, location, texture);
		location = get_next_tiletype_location(map, 'C', location.y,
				location.x + 1);
	}
}
