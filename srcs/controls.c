/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:20:42 by svassal           #+#    #+#             */
/*   Updated: 2016/10/08 18:08:39 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Move backward or forward
*/

void			move(t_env *e, t_player *p, float speed)
{
	speed = ((e->push[3] == 1 || e->push[5] == 1) &&
		(e->push[4] == 1 || e->push[1] == 1)) ? (speed * 0.75) : (speed);
	speed = (e->push[6] == 1) ? (speed * 1.5) : (speed);
	if (speed > 0)
	{
		if (e->map[access_map((int)(p->pos.x + p->dir.x * speed),
			(int)p->pos.y)] == 0)
			p->pos.x += p->dir.x * speed;
		if (e->map[access_map((int)p->pos.x,
			(int)(p->pos.y + p->dir.y * speed))] == 0)
			p->pos.y += p->dir.y * speed;
	}
	else
	{
		if (e->map[access_map((int)(p->pos.x - p->dir.x * -speed),
			(int)p->pos.y)] == 0)
			p->pos.x -= p->dir.x * -speed;
		if (e->map[access_map((int)p->pos.x,
			(int)(p->pos.y - p->dir.y * -speed))] == 0)
			p->pos.y -= p->dir.y * -speed;
	}
}

/*
** Rotate the player
*/

void			rotation(t_player *p, float angle)
{
	t_coord		old;

	old.x = p->dir.x;
	old.y = p->plane.x;
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = old.x * sin(angle) + p->dir.y * cos(angle);
	p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = old.y * sin(angle) + p->plane.y * cos(angle);
}

/*
** Move to the left or to the right
*/

void			strafing(t_env *e, t_player *p, int kc)
{
	rotation(p, M_PI / 2);
	if (kc == 12)
		move(e, p, 0.1);
	else
		move(e, p, -0.1);
	rotation(p, -(M_PI / 2));
}
