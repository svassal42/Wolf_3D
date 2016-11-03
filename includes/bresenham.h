/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:01:02 by svassal           #+#    #+#             */
/*   Updated: 2016/10/08 18:29:04 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H
# include "wolf.h"

/*
** Draw line using bresenham algorithm
*/

void		line(t_env *e, t_coord p1, t_coord p2, int c);

/*
** Draw both sky, walls, and floor
*/

void		draw_full_line(t_env *e, t_coord p1, t_coord p2, int c);

#endif
