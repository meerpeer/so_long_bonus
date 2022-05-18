/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:24:17 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/03/09 10:24:18 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*str;
	size_t			i;

	uc = c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*str == uc)
			return (str);
		i++;
		str++;
	}
	return (NULL);
}
