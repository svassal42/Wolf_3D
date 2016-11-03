/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:13:15 by svassal           #+#    #+#             */
/*   Updated: 2016/10/06 14:18:00 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H
# include "wolf.h"

/*
** Move backward or forward
*/

void			move(t_env *e, t_player *p, float speed);

/*
** Move to the left or the the right
*/

void			strafing(t_env *e, t_player *p, int kc);

/*
** Rotate the player
*/

void			rotation(t_player *p, float angle);

#endif
