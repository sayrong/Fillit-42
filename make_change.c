/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_change.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:45:27 by masprigg          #+#    #+#             */
/*   Updated: 2019/01/19 23:37:46 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_tetr_down_right(char **tetr, int down, int right)
{
	int i;
	int j;

	i = 3;
	while (i-- >= 0)
	{
		j = 3;
		while (j-- >= 0)
		{
			if (tetr[i][j] == '#')
			{
				tetr[i + down][j + right] = '#';
				tetr[i][j] = '.';
			}
		}
	}
}

void	move_tetr_up_left(char **tetr, int up, int left)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetr[i][j] == '#')
			{
				tetr[i - up][j - left] = '#';
				tetr[i][j] = '.';
			}
		}
	}
}

void	print_tetr(char **tetr, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_putendl(tetr[i++]);
}

void	make_correct_tetr(char **tetr)
{
	while (check_side(tetr, 1, 0, 0))
		move_tetr_up_left(tetr, 1, 0);
	while (check_side(tetr, 0, 0, 1))
		move_tetr_up_left(tetr, 0, 1);
}

int		change_position(char **tetr)
{
	if (check_side(tetr, 0, 0, 0))
	{
		move_tetr_down_right(tetr, 0, 1);
		return (1);
	}
	else if (check_side(tetr, 0, 1, 0))
	{
		move_tetr_down_right(tetr, 1, 0);
		while (check_side(tetr, 0, 0, 1))
			move_tetr_up_left(tetr, 0, 1);
		return (1);
	}
	return (0);
}
