/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 17:53:11 by mevan-de      #+#    #+#                 */
/*   Updated: 2021/12/16 09:21:01 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_for_type(const char flag, va_list args)
{
	if (flag == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (flag == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (flag == 'd' || flag == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (flag == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	if (flag == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 'x'));
	if (flag == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), 'X'));
	if (flag == '%')
		return (ft_putchar('%'));
	if (flag == 'p')
	{
		write(1, "0x", 2);
		return (2 + ft_puthexa(va_arg(args, unsigned long), 'p'));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count = count + exec_for_type(str[i], args);
		}
		else
			count = count + write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
