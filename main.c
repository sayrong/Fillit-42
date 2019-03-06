/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:39:42 by masprigg          #+#    #+#             */
/*   Updated: 2019/01/23 20:52:09 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_usage(int a)
{
	ft_putstr("usage: fillit input_file\n");
	return (a);
}

static int	ft_count(long r)
{
	if (r >= 440)
		return (r / 20 - 1);
	else
		return (r / 20);
}

static int	ft_error(int a)
{
	ft_putendl("error");
	return (a);
}

static int	get_content(char **buf, const char **argv, ssize_t *r)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	ME1((*buf = (char*)malloc(MAX_READ + 1)));
	*r = read(fd, *buf, MAX_READ + 1);
	if (*r > MAX_READ || *r == -1 || !ft_valid(*buf))
	{
		free(*buf);
		return (1);
	}
	(*buf)[*r] = 0;
	close(fd);
	return (0);
}

int			main(int argc, const char **argv)
{
	int				fd;
	char			*buf;
	int				e;
	ssize_t			r;
	t_tetro_block	**array_of_blocks;

	e = -1;
	if (argc != 2)
		return (ft_usage(1));
	if (get_content(&buf, argv, &r))
		return (ft_error(1));
	if (!(array_of_blocks = make_blocks(buf, ft_count(r))))
		return (ft_usage(1));
	if ((solve(array_of_blocks, 0, ft_count(r))))
		return (ft_usage(1));
	free(buf);
	return (0);
}
