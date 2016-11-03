/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 12:54:26 by svassal           #+#    #+#             */
/*   Updated: 2016/10/20 13:36:06 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Define a starting point, the first 0 (top - left)
*/

static int	set_start_point(t_env *e)
{
	int		i;

	i = -1;
	while (++i <= (M_WIDTH + 2) * (M_HEIGHT + 2) - 1)
	{
		if (e->map[i] == 0)
		{
			e->player->pos.y = (i / (M_WIDTH + 2)) + 0.5;
			e->player->pos.x = i - ((int)e->player->pos.y *
				(M_WIDTH + 2)) + 0.5;
			break ;
		}
	}
	if (e->player->pos.x == -1)
	{
		ft_putstr("No starting point avilable");
		ft_putendl(", try again with a different map.");
		return (0);
	}
	return (1);
}

/*
** Skip some columns and lines
*/

static int	skip_first_l_c(int i)
{
	while ((i / (M_WIDTH + 2) == 0 || i / (M_WIDTH + 2) == (M_HEIGHT + 1))
		&& i <= (M_WIDTH + 2) * (M_HEIGHT + 2) - 1)
		i++;
	while ((i / (M_WIDTH + 2) == 0 || i / (M_WIDTH + 2) == (M_HEIGHT + 1)))
		i++;
	while (i % (M_WIDTH + 2) == 0 || i % (M_WIDTH + 2) == (M_WIDTH + 1))
		i++;
	return (i);
}

/*
** Get 1 dimension coord using 2 dimensional ones
*/

int			access_map(int x, int y)
{
	return ((y * (M_WIDTH + 2)) + x);
}

/*
** Parse map
*/

int			get_map(t_env *e, int fd)
{
	char	c;
	int		i;
	int		t;

	i = -1;
	while ((t = read(fd, &c, 1)) == 1)
	{
		i = skip_first_l_c(i);
		if (c >= '0' && c <= '5')
		{
			if (i >= ((M_WIDTH + 2) * (M_HEIGHT + 2) - 1))
				break ;
			e->map[i++] = c - '0';
		}
	}
	if (i < ((M_WIDTH + 2) * (M_HEIGHT + 2) - (M_WIDTH + 2)) - 1 || t == 1)
	{
		ft_putendl("Wrong map, try again with a different one.");
		return (0);
	}
	if (set_start_point(e) == 0)
		return (0);
	return (1);
}
