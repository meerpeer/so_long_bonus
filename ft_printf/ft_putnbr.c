/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 17:56:20 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/06 11:17:14 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nr)
{
	int	count;

	count = 1;
	if (nr < 0)
	{
		write(1, "-", 1);
		count++;
		nr *= -1;
	}
	if (nr / 10 != 0)
		count = count + ft_putnbr(nr / 10);
	nr = nr % 10 + 48;
	write(1, &nr, 1);
	return (count);
}
