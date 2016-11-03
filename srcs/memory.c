/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:07:55 by svassal           #+#    #+#             */
/*   Updated: 2016/10/23 15:36:45 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Clean memory allocated to image
*/

static void	mem_clean_image(t_env *e, t_image *i)
{
	if (i != 0)
	{
		if (i->image != 0)
			mlx_destroy_image(e->mlx, i->image);
		i->image = 0;
		free(i);
	}
	i = 0;
}

/*
** Clean allocated memory to player and ray
*/

static void	mem_clean_p_r(t_env *e)
{
	if (e->player != 0)
	{
		free(e->player);
		e->player = 0;
	}
	if (e->ray != 0)
	{
		free(e->ray);
		e->ray = 0;
	}
}

/*
** Clean memory allocated to env
*/

void		mem_env_clean(t_env *e)
{
	if (e != 0)
	{
		mem_clean_image(e, e->image);
		mem_clean_p_r(e);
		if (e->window != 0)
			mlx_destroy_window(e->mlx, e->window);
		e->window = 0;
		if (e->mlx != 0)
			free(e->mlx);
		e->mlx = 0;
	}
	if (e != 0)
		free(e);
	e = 0;
}
