/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 17:51:02 by svassal           #+#    #+#             */
/*   Updated: 2016/10/23 15:38:07 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Display player position
*/

static void	display_coord(t_env *e)
{
	int		x;
	int		y;
	char	*x_str;
	char	*y_str;
	char	*tmp;

	x = (int)e->player->pos.x;
	y = (int)e->player->pos.y;
	x_str = ft_itoa(x);
	y_str = ft_itoa(y);
	tmp = ft_strjoin(x_str, " : ");
	free(x_str);
	x_str = ft_strjoin(tmp, y_str);
	mlx_string_put(e->mlx, e->window, 25, 25, 0xBB00BB, x_str);
	free(tmp);
	free(x_str);
	free(y_str);
}

/*
** Display player direction
*/

static void	display_comp(t_env *e)
{
	if (e->player->dir.x >= (1 - 0.125))
		mlx_string_put(e->mlx, e->window, 25, 45, 0xDD00DD, "WEST");
	else if (e->player->dir.x <= (-1 + 0.125))
		mlx_string_put(e->mlx, e->window, 25, 45, 0xDD00DD, "EAST");
	else if (e->player->dir.y >= (1 - 0.125))
		mlx_string_put(e->mlx, e->window, 25, 45, 0xDD00DD, "SOUTH");
	else if (e->player->dir.y <= (-1 + 0.125))
		mlx_string_put(e->mlx, e->window, 25, 45, 0xDD00DD, "NORTH");
	else if (e->player->dir.y > 0 && e->player->dir.x > 0)
		mlx_string_put(e->mlx, e->window, 25, 45, 0xDD00DD, "SOUTH-WEST");
	else if (e->player->dir.y > 0 && e->player->dir.x < 0)
		mlx_string_put(e->mlx, e->window, 25, 45, 0xDD00DD, "SOUTH-EAST");
	else if (e->player->dir.y < 0 && e->player->dir.x > 0)
		mlx_string_put(e->mlx, e->window, 25, 45, 0xDD00DD, "NORTH-WEST");
	else if (e->player->dir.y < 0 && e->player->dir.x < 0)
		mlx_string_put(e->mlx, e->window, 25, 45, 0xDD00DD, "NORTH-EAST");
}

/*
** Display compass infos on the screen if compass is true
*/

void		compass(t_env *e)
{
	if (e->compass == FALSE)
		return ;
	display_coord(e);
	display_comp(e);
}
