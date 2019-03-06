/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:53:23 by masprigg          #+#    #+#             */
/*   Updated: 2019/01/20 19:53:27 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_blocks(t_tetro_block **blocks, int t)
{
	int i;
	int j;

	i = 0;
	while (i < t)
	{
		j = 0;
		while (j < 4)
		{
			free(blocks[i]->tetr[j]);
			j++;
		}
		free(blocks[i]->tetr);
		free(blocks[i]);
		i++;
	}
	free(blocks);
}
