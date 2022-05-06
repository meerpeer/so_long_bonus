/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/24 16:51:31 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/06 13:55:57 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_move(int *move_count, mlx_image_t **img_count, mlx_t *mlx)
{
	char	*move_count_str;

	move_count_str = NULL;
	*move_count += 1;
	move_count_str = ft_itoa(*move_count);
	ft_printf("%i\n", *move_count);
	if (img_count)
		mlx_delete_image(mlx, *img_count);
	*img_count = mlx_put_string(mlx, move_count_str, 0, 0);
	free(move_count_str);
}
