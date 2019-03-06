/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:58:50 by masprigg          #+#    #+#             */
/*   Updated: 2019/01/20 19:42:55 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_tetro2(char **sstr)
{
	int		mat[4];
	int		i;
	int		j;
	int		n;

	i = -1;
	n = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 5)
		{
			if (sstr[i][j] == '1')
			{
				mat[n] = 0;
				if (i)
					mat[n] += sstr[i - 1][j] - 48;
				if (j)
					mat[n] += sstr[i][j - 1] - 48;
				n++;
			}
		}
	}
	CHECKMAT((mat[0] + mat[1] + mat[2] + mat[3]));
}

static void	leaknah(char **s)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		free(s[i]);
	}
	free(s);
}

static int	check_tetro(char *buf)
{
	char	**s;
	int		i;
	int		j;
	int		r;

	i = -1;
	j = -1;
	r = 0;
	s = (char**)malloc(sizeof(char*) * 4);
	while (++j < 4)
		s[j] = ft_strnew(5);
	while (++i < 20)
	{
		if (buf[i] != '\n' && buf[i] == '.')
			s[i / 5][i % 5] = '0';
		else if (buf[i] != '\n' && buf[i] == '#')
			s[i / 5][i % 5] = '1';
	}
	r = check_tetro2(s);
	leaknah(s);
	return (r);
}

int			ft_valid(char *buf)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	CHECKEND(buf[ft_strlen(buf) - 1], buf[ft_strlen(buf) - 2]);
	while (i < 20)
	{
		if ((i + 1) % 5 && buf[i] != '.' && buf[i] != '#')
			return (0);
		if (!((i + 1) % 5) && buf[i] != '\n')
			return (0);
		(buf[i] == '#') ? (count++) : ((void)0);
		i++;
	}
	if (count != 4 || !check_tetro(buf))
		return (0);
	if (buf[i + 1] && buf[i] != '\0')
		return (ft_valid(&buf[i + 1]));
	return (1);
}

int			floorsqrt(int nb)
{
	int		p;

	p = 1;
	while (p * p < nb)
		p++;
	return (p);
}
