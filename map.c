/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:44:03 by masprigg          #+#    #+#             */
/*   Updated: 2019/01/23 20:44:29 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*new_map(int size)
{
	t_map	*tmp;
	char	**tmp_map;
	int		i;
	int		j;

	i = 0;
	ME0((tmp = malloc(sizeof(t_map))));
	ME0((tmp_map = (char**)malloc(sizeof(char*) * size)));
	while (i < size)
	{
		j = 0;
		ME0((tmp_map[i] = (char *)malloc(sizeof(size + 1))));
		tmp_map[i][size] = 0;
		while (j < size)
			tmp_map[i][j++] = '.';
		i++;
	}
	tmp->map = tmp_map;
	tmp->size = size;
	return (tmp);
}

void	get_off_map(t_map *my_map, t_tetro_block *my_block)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (my_block->tetr[i][j] == '#')
				my_map->map[i + my_block->down][j + my_block->right] = '.';
		}
	}
}

int		is_save_put_on_map(t_map *my_map, t_tetro_block *my_block)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (my_block->tetr[i][j] == '#')
			{
				if ((my_block->right + j > my_map->size - 1)
					|| (my_block->down + i > my_map->size - 1))
					return (0);
				if (my_map->map[i + my_block->down][j + my_block->right] != '.')
					return (0);
			}
		}
	}
	return (1);
}

void	put_on_map(t_map *my_map, t_tetro_block *my_block)
{
	int		i;
	int		j;
	int		d;
	int		r;

	i = -1;
	d = my_block->down;
	r = my_block->right;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (my_block->tetr[i][j] == '#')
				my_map->map[i + d][j + r] = my_block->symbol;
		}
	}
}

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	while (i < (*map)->size)
	{
		free((*map)->map[i]);
		i++;
	}
	free((*map)->map);
	free(*map);
}
