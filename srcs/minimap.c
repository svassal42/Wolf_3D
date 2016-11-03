/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:38:16 by svassal           #+#    #+#             */
/*   Updated: 2016/10/23 15:31:43 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#define P_WIDTH		7
#define B_WIDTH		3
#define T_WIDTH		(25 * P_WIDTH + B_WIDTH * 2)

/*
** Draws the minimap background
*/

static void	map_background(t_image *i)
{
	int		index;

	index = -1;
	while (++index < T_WIDTH * T_WIDTH)
		*(i->beg + index) = 0x55333333;
}

/*
** Draw a "thick" pixel
*/

static void	draw_pixel_s(t_image *i, int x, int y, int color)
{
	int		p;
	int		j;
	int		k;

	p = (y * P_WIDTH + B_WIDTH) * T_WIDTH;
	p = p + B_WIDTH + (x * P_WIDTH);
	j = -1;
	while (++j < P_WIDTH)
	{
		k = -1;
		while (++k < P_WIDTH)
			*(i->beg + p + (j * T_WIDTH) + k) = color;
	}
}

/*
** Draw the map arround the player pos
*/

static void	draw_map(t_env *e, t_image *i)
{
	int		x_play;
	int		y_play;
	int		x;
	int		y;

	x_play = (int)e->player->pos.x;
	y_play = (int)e->player->pos.y;
	x = -1;
	while (++x < 25)
	{
		y = -1;
		while (++y < 25)
		{
			if (((x_play - 12 + x) >= 0 && (y_play - 12 + y) >= 0) &&
				((x_play - 12 + x) <= M_WIDTH + 1 && (y_play - 12 + y)
					<= M_HEIGHT + 1))
				if (e->map[access_map(x_play - 12 + x, y_play - 12 + y)] != 0)
					draw_pixel_s(i, x, y, 0x55FFFFFF);
		}
	}
}

/*
** Draw a green point for the player direction
*/

static void	draw_dir(t_env *e, t_image *i)
{
	if (e->player->dir.x >= (1 - 0.125))
		draw_pixel_s(i, 13, 12, 0x5500FF00);
	else if (e->player->dir.x <= (-1 + 0.125))
		draw_pixel_s(i, 11, 12, 0x5500FF00);
	else if (e->player->dir.y >= (1 - 0.125))
		draw_pixel_s(i, 12, 13, 0x5500FF00);
	else if (e->player->dir.y <= (-1 + 0.125))
		draw_pixel_s(i, 12, 11, 0x5500FF00);
	else if (e->player->dir.y > 0 && e->player->dir.x > 0)
		draw_pixel_s(i, 13, 13, 0x5500FF00);
	else if (e->player->dir.y > 0 && e->player->dir.x < 0)
		draw_pixel_s(i, 11, 13, 0x5500FF00);
	else if (e->player->dir.y < 0 && e->player->dir.x > 0)
		draw_pixel_s(i, 13, 11, 0x5500FF00);
	else if (e->player->dir.y < 0 && e->player->dir.x < 0)
		draw_pixel_s(i, 11, 11, 0x5500FF00);
}

/*
** Draw the minimap if enabled in the env
*/

void		draw_minimap(t_env *e)
{
	t_image		*map;

	if (e->minimap == TRUE)
	{
		if ((map = malloc(sizeof(t_image))) == 0)
			return ;
		map->image = mlx_new_image(e->mlx, T_WIDTH, T_WIDTH);
		map->beg = (int *)mlx_get_data_addr(map->image,
			&map->bpp, &map->size_l, &map->endian);
		map_background(map);
		draw_map(e, map);
		draw_pixel_s(map, 12, 12, 0x55FF0000);
		draw_dir(e, map);
		mlx_put_image_to_window(e->mlx, e->window,
			map->image, 1278 - T_WIDTH, 2);
		mlx_destroy_image(e->mlx, map->image);
		free(map);
		map = 0;
	}
}
