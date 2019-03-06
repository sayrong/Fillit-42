/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:55:30 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/12 01:19:38 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	d;
	unsigned char	e;
	unsigned char	y;

	y = (unsigned char)c;
	d = 0;
	e = 0;
	if (y < 128)
		write(fd, &y, 1);
	else
	{
		d = 128 + 64 + (y >> 6);
		e = 128 + (y & 63);
		write(fd, &d, 1);
		write(fd, &e, 1);
	}
}
