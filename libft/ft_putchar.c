/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:25:35 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/13 17:29:10 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char	d;
	unsigned char	e;
	unsigned char	y;

	y = (unsigned char)c;
	d = 0;
	e = 0;
	if (y < 128)
		write(1, &y, 1);
	else
	{
		d = 128 + 64 + (y >> 6);
		e = 128 + (y & 63);
		write(1, &d, 1);
		write(1, &e, 1);
	}
}
