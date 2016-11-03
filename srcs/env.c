/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:17:32 by svassal           #+#    #+#             */
/*   Updated: 2016/10/23 15:36:11 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#define PX	0
#define PY	0.66

/*
** Initialize image variable
*/

t_image			*init_image(t_env *e)
{
	t_image		*img;

	if ((img = malloc(sizeof(t_image))) == 0)
		return (0);
	img->image = mlx_new_image(e->mlx, e->w_width, e->w_height);
	img->beg = (int *)mlx_get_data_addr(img->image,
		&(img->bpp), &(img->size_l), &(img->endian));
	return (img);
}

/*
** Initialize the map with each case of value 1
*/

static void		init_map(t_env *e)
{
	int		index;

	index = -1;
	while (++index <= (M_WIDTH + 2) * (M_HEIGHT + 2) - 1)
		e->map[index] = 1;
}

/*
** Initialize player values
*/

static t_player	*init_player(void)
{
	t_player	*p;

	if ((p = malloc(sizeof(t_player))) == 0)
		return (0);
	p->dir.x = -1;
	p->dir.y = 0;
	p->plane.x = PX;
	p->plane.y = PY;
	p->pos.x = -1;
	p->pos.y = -1;
	return (p);
}

/*
** Initialize work environement
*/

t_env			*init_env(void)
{
	t_env		*e;
	int			i;

	if ((e = malloc(sizeof(t_env))) == 0)
		return (0);
	e->mlx = mlx_init();
	e->w_width = W_WIDTH;
	e->w_height = W_HEIGHT;
	e->window = mlx_new_window(e->mlx, e->w_width, e->w_height, "WOLF 3D");
	if ((e->image = init_image(e)) == 0)
		return (0);
	if ((e->ray = malloc(sizeof(t_ray))) == 0)
		return (0);
	if ((e->player = init_player()) == 0)
		return (0);
	i = -1;
	while (++i < 8)
		e->push[i] = 0;
	e->compass = FALSE;
	e->minimap = FALSE;
	init_map(e);
	return (e);
}
