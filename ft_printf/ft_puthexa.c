/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexa.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 17:55:57 by mevan-de      #+#    #+#                 */
/*   Updated: 2021/12/16 08:55:19 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long long nr, char c)
{
	int		count;
	char	*hexstr;

	if (c == 'x' || c == 'p')
		hexstr = "0123456789abcdef";
	else
		hexstr = "0123456789ABCDEF";
	count = 1;
	if (nr / 16 != 0)
		count += ft_puthexa(nr / 16, c);
	nr = nr % 16;
	write(1, &hexstr[nr], 1);
	return (count);
}
