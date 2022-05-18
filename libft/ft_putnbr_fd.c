/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:24:58 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/03/09 10:24:59 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_nbr(long n, int fd)
{
	if (n > 9)
		ft_putnbr_fd (n / 10, fd);
	ft_putchar_fd((n % 10 + '0'), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nr;

	nr = n;
	if (nr < 0)
	{
		write(fd, "-", 1);
		nr *= -1;
	}
	put_nbr(nr, fd);
}
