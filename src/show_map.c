/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   show_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 11:37:46 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/19 14:49:08 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*create_img_at_pos(void *mlx, mlx_texture_t *texture,
	t_2dVector location)
{
	mlx_image_t	*image;

	image = mlx_new_image(mlx, SIZE, SIZE);
	if (!image)
		exit (0);
	mlx_draw_texture(image, texture, 0, 0);
	mlx_image_to_window(mlx, image, SIZE * location.x, SIZE * location.y);
	return (image);
}

mlx_image_t	*create_background_image(void *mlx, int width, int height)
{
	mlx_image_t	*img_background;

	img_background = mlx_new_image(mlx, SIZE * width, SIZE * height);
	if (!img_background)
		exit(0);
	mlx_image_to_window(mlx, img_background, 0, 0);
	return (img_background);
}

int	draw_background_tile(mlx_image_t *img, t_2dVector map_location,
	t_sprites sprites, char **map)
{
	int	x;
	int	y;

	x = map_location.x;
	y = map_location.y;
	mlx_draw_texture(img, sprites.floor, x * SIZE, y * SIZE);
	if (map[y][x] == '1')
		mlx_draw_texture(img, sprites.wall, x * SIZE, y * SIZE);
	return (0);
}

void	draw_background(char **map, t_sprites sprites,
	mlx_image_t *img_background)
{
	t_2dVector	location;

	location.y = 0;
	while (map[location.y])
	{
		location.x = 0;
		while (map[location.y][location.x])
		{
			draw_background_tile(img_background, location, sprites, map);
			location.x++;
		}
		location.y++;
	}
}
