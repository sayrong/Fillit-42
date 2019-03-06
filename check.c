/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:40:05 by masprigg          #+#    #+#             */
/*   Updated: 2019/01/20 20:13:21 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_end_tetr(t_map *my_map, t_tetro_block *my_block)
{
	int		i;
	int		j;
	int		bottom;
	int		rig;

	bottom = 0;
	rig = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (my_block->tetr[i][j] == '#')
			{
				if (j + my_block->right == my_map->size)
					rig = 1;
				if (i + my_block->down == my_map->size)
					bottom = 1;
			}
			j++;
		}
		i++;
	}
	return (bottom && rig);
}

int		check_side(char **tetr, int up, int down, int left)
{
	int		i;
	int		t;

	i = 0;
	if (up == 1 || down == 1)
	{
		t = up == 1 ? 0 : 3;
		while (i < 4)
		{
			if (tetr[t][i] == '#')
				return (0);
			i++;
		}
	}
	else
	{
		t = left == 1 ? 0 : 3;
		while (i < 4)
		{
			if (tetr[i][t] == '#')
				return (0);
			i++;
		}
	}
	return (1);
}

void	reset_block(t_tetro_block **blocks, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		blocks[i]->right = 0;
		blocks[i]->down = 0;
		i++;
	}
}
