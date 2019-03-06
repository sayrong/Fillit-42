/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetroblock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:35:52 by masprigg          #+#    #+#             */
/*   Updated: 2019/01/23 20:57:44 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**get_array(char *buf)
{
	char	**ar;
	int		i;
	int		j;

	i = -1;
	ME0((ar = (char **)malloc(sizeof(char *) * 4)));
	while (++i < 4)
	{
		j = 0;
		ME0((ar[i] = (char *)malloc(sizeof(5))));
		ar[i][5] = 0;
		while (j < 4)
			ar[i][j++] = *buf++;
		if (*buf)
			buf++;
	}
	return (ar);
}

t_tetro_block	*new_block(int i, char *buf)
{
	t_tetro_block	*tmp;
	char			**tmp_map;

	ME0((tmp = malloc(sizeof(t_tetro_block))));
	tmp->down = 0;
	tmp->right = 0;
	ME0((tmp_map = get_array(buf)));
	make_correct_tetr(tmp_map);
	tmp->tetr = tmp_map;
	tmp->symbol = 'A' + i;
	return (tmp);
}

t_tetro_block	**make_blocks(char *buf, int nblocks)
{
	t_tetro_block	**blocks;
	int				i;

	i = 0;
	ME0((blocks = (t_tetro_block **)malloc(sizeof(t_tetro_block*) * nblocks)));
	while (nblocks)
	{
		ME0((blocks[i] = new_block(i, buf)));
		buf += 21;
		nblocks--;
		i++;
	}
	return (blocks);
}

static int		solve_tetr(t_map *map, t_tetro_block **blocks, int bget, int t)
{
	int	i;

	i = 0;
	if (bget == t)
		return (1);
	while (!check_end_tetr(map, blocks[bget]))
	{
		if (is_save_put_on_map(map, blocks[bget]))
		{
			put_on_map(map, blocks[bget]);
			if (solve_tetr(map, blocks, bget + 1, t))
				return (1);
			get_off_map(map, blocks[bget]);
		}
		if (blocks[bget]->right != map->size)
			blocks[bget]->right += 1;
		else if (blocks[bget]->down != map->size)
		{
			blocks[bget]->right = 0;
			blocks[bget]->down += 1;
		}
	}
	blocks[bget]->right = 0;
	blocks[bget]->down = 0;
	return (0);
}

int				solve(t_tetro_block **blocks, int bget, int t)
{
	int		map_size;
	t_map	*mymap;

	map_size = floorsqrt(t * 4);
	ME1((mymap = new_map(map_size)));
	while (!solve_tetr(mymap, blocks, bget, t))
	{
		free_map(&mymap);
		map_size++;
		mymap = new_map(map_size);
		reset_block(blocks, t);
	}
	print_tetr(mymap->map, mymap->size);
	free_map(&mymap);
	free_blocks(blocks, t);
	return (0);
}
