/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:20:46 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/19 13:07:18 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# define BUFFER_SIZE 400

char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	*ft_memmove_gnl(void *dst, const void *src, size_t len);
char	*ft_strndup_gnl(char *s1, int n);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
#endif
