/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:51:42 by jandre-j          #+#    #+#             */
/*   Updated: 2015/12/16 13:09:44 by jandre-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{
	size_t	size;
	long	buffer;
	int		negative;
	char	*rslt;

	size = 0;
	buffer = (long)n;
	negative = (buffer < 0);
	while (buffer /= 10)
		size++;
	if ((rslt = (char *)malloc(sizeof(char) * (++size + negative + 1))) == NULL)
		return (NULL);
	rslt[size + negative] = '\0';
	rslt[0] = '-';
	buffer = (long)n;
	buffer = (negative ? -buffer : buffer);
	while (size--)
	{
		rslt[size + negative] = buffer % 10 + '0';
		buffer /= 10;
	}
	return (rslt);
}
