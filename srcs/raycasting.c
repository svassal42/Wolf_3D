/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:21:22 by svassal           #+#    #+#             */
/*   Updated: 2016/10/20 15:17:23 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#define RGB_RED 0xFF0000
#define RGB_GRN 0x00FF00
#define RGB_BLU 0X0000FF
#define RGB_WHT 0XFFFFFF
#define RGB_YEL 0XFFFF00

/*
** Initialize numbers used for the raycasting function
*/

static void	nbr_init(t_env *e, int x, float *cam_x)
{
	*cam_x = 2 * x / (float)e->w_width - 1;
	e->ray->pos.x = e->player->pos.x;
	e->ray->pos.y = e->player->pos.y;
	e->ray->dir.x = e->player->dir.x + e->player->plane.x * (*cam_x);
	e->ray->dir.y = e->player->dir.y + e->player->plane.y * (*cam_x);
	e->ray->d_dist.x = sqrt(1 + (e->ray->dir.y * e->ray->dir.y)
		/ (e->ray->dir.x * e->ray->dir.x));
	e->ray->d_dist.y = sqrt(1 + (e->ray->dir.x * e->ray->dir.x)
		/ (e->ray->dir.y * e->ray->dir.y));
	e->ray->hit = 0;
	e->ray->side = 0;
}

/*
** Calcul the distance from the side of the "squares"
*/

static void	step_side_calc(t_env *e, t_coord m)
{
	if (e->ray->dir.x < 0)
	{
		e->ray->step.x = -1;
		e->ray->s_dist.x = (e->ray->pos.x - m.x) * e->ray->d_dist.x;
	}
	else
	{
		e->ray->step.x = 1;
		e->ray->s_dist.x = (m.x + 1.0 - e->ray->pos.x) * e->ray->d_dist.x;
	}
	if (e->ray->dir.y < 0)
	{
		e->ray->step.y = -1;
		e->ray->s_dist.y = (e->ray->pos.y - m.y) * e->ray->d_dist.y;
	}
	else
	{
		e->ray->step.y = 1;
		e->ray->s_dist.y = (m.y + 1.0 - e->ray->pos.y) * e->ray->d_dist.y;
	}
}

/*
** DDA Algorithm
*/

static void	dda(t_env *e, t_coord *m)
{
	while (e->ray->hit == 0)
	{
		if (e->ray->s_dist.x < e->ray->s_dist.y)
		{
			e->ray->s_dist.x += e->ray->d_dist.x;
			m->x += (int)e->ray->step.x;
			e->ray->side = 0;
			if (e->ray->step.x == 1)
				e->ray->side = 1;
		}
		else
		{
			e->ray->s_dist.y += e->ray->d_dist.y;
			m->y += (int)e->ray->step.y;
			e->ray->side = 3;
			if (e->ray->step.y == 1)
				e->ray->side = 4;
		}
		if (e->map[access_map((int)m->x, (int)m->y)] > 0)
			e->ray->hit = 1;
	}
}

/*
** Calcul the stripes to draw
*/

static void	strip_calc(t_env *e, int n[3], t_coord m)
{
	float	pwd;
	int		l_h;

	if (e->ray->side < 2)
		pwd = (m.x - e->ray->pos.x + (1 - e->ray->step.x) / 2) / e->ray->dir.x;
	else
		pwd = (m.y - e->ray->pos.y + (1 - e->ray->step.y) / 2) / e->ray->dir.y;
	l_h = (int)(e->w_height / pwd);
	n[0] = -(l_h) / 2 + e->w_height / 2;
	if (n[0] < 0)
		n[0] = 0;
	n[1] = l_h / 2 + e->w_height / 2;
	if (n[1] >= e->w_height)
		n[1] = e->w_height - 1;
	n[2] = RGB_YEL;
	if (e->map[access_map((int)m.x, (int)m.y)] == 1)
		n[2] = RGB_RED;
	else if (e->map[access_map((int)m.x, (int)m.y)] == 2)
		n[2] = RGB_GRN;
	else if (e->map[access_map((int)m.x, (int)m.y)] == 3)
		n[2] = RGB_BLU;
	else if (e->map[access_map((int)m.x, (int)m.y)] == 4)
		n[2] = RGB_WHT;
	n[2] = n[2] / (e->ray->side + 1) * 0.5;
}

/*
** Launch raycasting for current player pos
*/

void		raycasting(t_env *e)
{
	float		cam_x;
	t_coord		map;
	int			x;
	int			dr[3];
	t_coord		p[2];

	x = -1;
	while (++x < e->w_width)
	{
		nbr_init(e, x, &cam_x);
		map.x = (int)e->ray->pos.x;
		map.y = (int)e->ray->pos.y;
		step_side_calc(e, map);
		dda(e, &map);
		strip_calc(e, dr, map);
		p[0].x = x;
		p[0].y = dr[0];
		p[1].x = x;
		p[1].y = dr[1];
		draw_full_line(e, p[0], p[1], dr[2]);
	}
	mlx_put_image_to_window(e->mlx, e->window, e->image->image, 0, 0);
	compass(e);
	draw_minimap(e);
}
