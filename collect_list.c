/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collect_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 16:56:53 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/10 17:18:18 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_collect	*new_lstcollect(mlx_image_t *img, int x, int y)
{
	t_collect	*new_collect;

	new_collect = malloc (sizeof(struct s_collect));
	if (!new_collect)
		return (NULL);
	printf("malloc worked\n");
	new_collect->x = x;
	new_collect->y = y;
	new_collect->img_collect = img;
	new_collect->next = NULL;
	return (new_collect);
}

void	lstcollect_addback(t_collect **lst, t_collect *new)
{
	t_collect	*last;

	printf("yep\n");
	last = *lst;
	if (*lst)
	{
		printf("lst exists somehow\n");
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*lst = new;
	printf("should be added\n");
}
