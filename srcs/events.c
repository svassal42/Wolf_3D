/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:21:17 by svassal           #+#    #+#             */
/*   Updated: 2016/10/20 12:42:33 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#define CMP	((t_env *)p)->compass
#define MMP	((t_env *)p)->minimap

/*
** Exit program
*/

static int	exit_program(t_env *e)
{
	mem_env_clean(e);
	exit(1);
}

/*
** MLX expose management
*/

static int	exp_h(void *p)
{
	if (((t_env *)p)->push[7])
		exit_program((t_env *)p);
	if (((t_env *)p)->push[0])
		rotation(((t_env *)p)->player, 0.05);
	if (((t_env *)p)->push[2])
		rotation(((t_env *)p)->player, -0.05);
	if (((t_env *)p)->push[4])
		move((t_env *)p, ((t_env *)p)->player, 0.1);
	if (((t_env *)p)->push[1])
		move((t_env *)p, ((t_env *)p)->player, -0.1);
	if (((t_env *)p)->push[3])
		strafing((t_env *)p, ((t_env *)p)->player, 12);
	if (((t_env *)p)->push[5])
		strafing((t_env *)p, ((t_env *)p)->player, 14);
	mlx_clear_window(((t_env *)p)->mlx, ((t_env *)p)->window);
	clean_image((t_env *)p);
	raycasting((t_env *)p);
	return (0);
}

/*
** Manage key release
*/

static int	k_r(int kc, void *p)
{
	if (kc == 0)
		((t_env *)p)->push[0] = 0;
	if (kc == 1)
		((t_env *)p)->push[1] = 0;
	if (kc == 2)
		((t_env *)p)->push[2] = 0;
	if (kc == 8)
		CMP = (CMP == TRUE) ? (FALSE) : (TRUE);
	if (kc == 12)
		((t_env *)p)->push[3] = 0;
	if (kc == 13)
		((t_env *)p)->push[4] = 0;
	if (kc == 14)
		((t_env *)p)->push[5] = 0;
	if (kc == 46)
		MMP = (MMP == TRUE) ? (FALSE) : (TRUE);
	if (kc == 53)
		((t_env *)p)->push[7] = 0;
	if (kc == 257)
		((t_env *)p)->push[6] = 0;
	return (0);
}

/*
** Manage key press
*/

static int	k_p(int kc, void *p)
{
	if (kc == 0)
		((t_env *)p)->push[0] = 1;
	if (kc == 1)
		((t_env *)p)->push[1] = 1;
	if (kc == 2)
		((t_env *)p)->push[2] = 1;
	if (kc == 12)
		((t_env *)p)->push[3] = 1;
	if (kc == 13)
		((t_env *)p)->push[4] = 1;
	if (kc == 14)
		((t_env *)p)->push[5] = 1;
	if (kc == 53)
		((t_env *)p)->push[7] = 1;
	if (kc == 257)
		((t_env *)p)->push[6] = 1;
	return (0);
}

/*
** MLX event management
*/

void		event(t_env *e)
{
	mlx_hook(e->window, 17, 0, exit_program, (void *)e);
	mlx_hook(e->window, 2, 1, k_p, (void *)e);
	mlx_hook(e->window, 3, 2, k_r, (void *)e);
	mlx_expose_hook(e->window, exp_h, (void *)e);
	mlx_loop_hook(e->mlx, exp_h, (void *)e);
	mlx_loop(e->mlx);
}
