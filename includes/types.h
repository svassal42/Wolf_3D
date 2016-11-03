/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:20:00 by svassal           #+#    #+#             */
/*   Updated: 2016/10/20 12:38:02 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "wolf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef enum		e_bool
{
	FALSE, TRUE
}					t_bool;
typedef struct		s_coord
{
	float			x;
	float			y;
}					t_coord;
typedef struct		s_ray
{
	t_coord			pos;
	t_coord			dir;
	t_coord			step;
	t_coord			s_dist;
	t_coord			d_dist;
	int				hit;
	int				side;
}					t_ray;
typedef struct		s_player
{
	t_coord			pos;
	t_coord			dir;
	t_coord			plane;
}					t_player;
typedef struct		s_image
{
	void			*image;
	int				*beg;
	int				bpp;
	int				size_l;
	int				endian;
}					t_image;
typedef struct		s_env
{
	void			*mlx;
	void			*window;
	int				w_width;
	int				w_height;
	t_image			*image;
	t_player		*player;
	t_ray			*ray;
	int				push[8];
	t_bool			compass;
	t_bool			minimap;
	int				map[(M_HEIGHT + 2) * (M_WIDTH + 2)];
}					t_env;

#endif
