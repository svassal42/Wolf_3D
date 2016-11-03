/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:14:17 by svassal           #+#    #+#             */
/*   Updated: 2016/10/08 18:24:43 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int argc, char **argv)
{
	t_env			*e;
	int				fd;

	if (argc != 2)
	{
		ft_putendl("Usage : wolf [map]");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 3)
	{
		ft_putendl("Unable to open map, try again with a different name.");
		return (0);
	}
	if ((e = init_env()) == 0)
	{
		mem_env_clean(e);
		return (0);
	}
	if (get_map(e, fd) == 0)
	{
		mem_env_clean(e);
		return (0);
	}
	event(e);
	return (0);
}
