/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 13:29:17 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/03/16 18:10:33 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



// typedef struct s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		edian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// typedef struct s_var {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	key_hook(int keycode, t_vars *vars)
// {
// 	if (keycode == KEY_W)
// 		printf("key: W\n");
// 	if (keycode == KEY_A)
// 		printf("key: A\n");
// 	if (keycode == KEY_S)
// 		printf("key: S\n");
// 	if (keycode == KEY_D)
// 		printf("key: D\n");
// 	if (keycode == KEY_ESC)
// 		printf("key: ESC\n");
// 	return (0);
// }

// int	mouse_hook(int mousecode, t_vars *vars)
// {
// 	printf("mouse: %i\n", mousecode);
// 	return (0);
// }

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

int	main(int argc, char *argv[])
{

	//char **map = NULL;


	//t_vars	vars;
//
	//t_data	img;
	//
//


	// SOOOO if I use a file path for the FD I don't have leaks, if I use the argv I do?! WHY?!


	// map = read_map(argc, argv, map);
	// printf("map[0] = %s", map[0]);

	// free(map);

	int		fd;
	char	*result;

	fd = open("min.ber", O_RDONLY);
	result = get_next_line(fd);
	while (result)
	{
		printf("%s", result);
		free(result);
		result = get_next_line(fd);
	}
	free (result);
	system("leaks game");
	return (0);

// 	vars.mlx = mlx_init();

// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 	//mlx_loop_hook(mlx, render_next_frame, )
// //
// 	// img.img = mlx_new_image(vars.mlx, 1920, 1080);
// 	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 	// 		&img.edian);
// 	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// //
// 	mlx_loop(vars.mlx);
	return (0);
}
 