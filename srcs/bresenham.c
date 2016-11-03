/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:00:10 by svassal           #+#    #+#             */
/*   Updated: 2016/10/08 11:40:38 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#define DX	n[0]
#define SX	n[1]
#define DY	n[2]
#define SY	n[3]
#define ERR	n[4]
#define E2	n[5]
#define X0	p[0]
#define X1	p[1]
#define Y0	p[2]
#define Y1	p[3]

/*
** Draw sky and floor
*/

static void	sky_and_floor(t_env *e, t_coord p1, t_coord p2)
{
	t_coord		t;

	t.x = p1.x;
	if (p1.y != 0)
	{
		t.y = 0;
		line(e, t, p1, 0xC0FFEE);
	}
	if (p2.y != e->w_height - 1)
	{
		t.y = e->w_height - 1;
		line(e, p2, t, 0x6600);
	}
}

/*
** Init numbers for bresenham line drawer
*/

static void	nbr_init(t_coord p1, t_coord p2, int n[6], int p[4])
{
	X0 = (int)p1.x;
	X1 = (int)p2.x;
	Y0 = (int)p1.y;
	Y1 = (int)p2.y;
	DX = ft_abs(X1 - X0);
	SX = (X0 < X1) ? (1) : (-1);
	DY = ft_abs(Y1 - Y0);
	SY = (Y0 < Y1) ? (1) : (-1);
	ERR = ((DX > DY) ? (DX) : (-DY)) / 2;
}

/*
** Draw line using bresenham algorithm
*/

void		line(t_env *e, t_coord p1, t_coord p2, int c)
{
	int		n[6];
	int		p[4];

	nbr_init(p1, p2, n, p);
	while (1)
	{
		draw_pixel_image(e, X0, Y0, c);
		if (X0 == X1 && Y0 == Y1)
			break ;
		E2 = ERR;
		if (E2 > -DX)
		{
			ERR -= DY;
			X0 += SX;
		}
		if (E2 < DY)
		{
			ERR += DX;
			Y0 += SY;
		}
	}
}

/*
** Draw both sky, walls, and floor
*/

void		draw_full_line(t_env *e, t_coord p1, t_coord p2, int c)
{
	sky_and_floor(e, p1, p2);
	line(e, p1, p2, c);
}
