/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:18:31 by svassal           #+#    #+#             */
/*   Updated: 2016/10/03 16:19:00 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "wolf.h"

/*
** Draw a pixel to the image
*/

void		draw_pixel_image(t_env *e, int x, int y, int color);

/*
** Clean the image
*/

void		clean_image(t_env *e);

#endif
