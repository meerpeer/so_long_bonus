/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:23:26 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/19 13:14:41 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert_to_str(char *dest, long nr, int len)
{
	dest[len] = '\0';
	len--;
	if (nr < 0)
	{
		dest[0] = '-';
		nr *= -1;
	}
	while (nr > 0)
	{
		dest[len] = nr % 10 + '0';
		nr = nr / 10;
		len--;
	}
	return (dest);
}

static int	get_len(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nr;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	nr = n;
	len = (get_len(nr));
	str = ft_malloc(sizeof(char) * (len + 1));
	if (str)
		str = convert_to_str(str, nr, len);
	return (str);
}
