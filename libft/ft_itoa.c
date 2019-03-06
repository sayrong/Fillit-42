/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:06:38 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/11 01:13:47 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	ft_nbrlen(int n)
{
	int	long	p;
	int			l;

	l = 0;
	p = (long)(n);
	if (p == 0)
		l++;
	if (p < 0)
	{
		l++;
		p *= -1;
	}
	while (p)
	{
		p /= 10;
		l++;
	}
	return (l);
}

char		*ft_itoa(int n)
{
	int		len;
	int		l;
	char	*itoa;
	long	p;

	len = ft_nbrlen(n);
	l = len;
	p = (long)(n);
	if (!(itoa = (char*)malloc(sizeof(*itoa) * (len + 1))))
		return (NULL);
	if (p < 0)
	{
		itoa[0] = '-';
		p *= -1;
	}
	if (p == 0)
		itoa[0] = 48;
	while (len--)
	{
		if (itoa[len] != '-')
			itoa[len] = p % 10 + 48;
		p /= 10;
	}
	itoa[l] = '\0';
	return (itoa);
}
