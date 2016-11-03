/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 12:53:47 by svassal           #+#    #+#             */
/*   Updated: 2016/10/08 18:14:29 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "wolf.h"

/*
** Get 1 dimension coord using 2 dimensional ones
*/

int			access_map(int x, int y);

/*
** Parse map
*/

int			get_map(t_env *e, int fd);

#endif
