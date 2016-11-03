/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:09:57 by svassal           #+#    #+#             */
/*   Updated: 2016/10/03 16:19:08 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Clean the image
*/

void		clean_image(t_env *e)
{
	int		max;
	int		index;

	max = (e->w_width * e->w_height);
	index = -1;
	while (++index < max)
		*(e->image->beg + index) = 0x55333333;
}

/*
** Draw a pixel to the image
*/

void		draw_pixel_image(t_env *e, int x, int y, int color)
{
	int		pos;

	pos = x + (y * e->w_width);
	*(e->image->beg + pos) = color;
}
