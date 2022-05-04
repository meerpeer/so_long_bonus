/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/24 16:51:31 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/04 11:07:30 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_move(int *move_count)
{
	*move_count += 1;
	ft_printf("%i\n", *move_count);
}
