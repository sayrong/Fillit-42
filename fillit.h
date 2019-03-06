/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:41:24 by masprigg          #+#    #+#             */
/*   Updated: 2019/01/23 20:47:30 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

# define MAX_READ 545
# define CHECKMAT(sum) return ((sum >= 3 && sum <= 4) ? (1) : (0));
# define CHECKEND(a, b) if (a == 10 && b == 10) return (0);
# define ME0(e) if (!e) return (0);
# define ME1(e) if (!e) return (1);

typedef struct		s_map
{
	int		size;
	char	**map;
}					t_map;

typedef struct		s_tetro_block
{
	char	symbol;
	int		right;
	int		down;
	char	**tetr;
}					t_tetro_block;

char				**get_array(char *buf);
t_tetro_block		*new_block(int i, char *buf);
t_tetro_block		**make_blocks(char *buf, int count_blocks);
int					solve(t_tetro_block **blocks, int bget, int t);

int					check_end_tetr(t_map *my_map, t_tetro_block *my_block);
int					check_side(char **tetr, int up, int down, int left);
void				reset_block(t_tetro_block **blocks, int total);

int					change_position(char **tetr);
void				make_correct_tetr(char **tetr);
void				move_tetr_down_right(char **tetr, int down, int right);
void				move_tetr_up_left(char **tetr, int up, int left);
void				print_tetr(char **tetr, int size);

t_map				*new_map(int size);
void				get_off_map (t_map *my_map, t_tetro_block *my_block);
int					is_save_put_on_map(t_map *my_map, t_tetro_block *my_block);
void				put_on_map(t_map *my_map, t_tetro_block *my_block);
void				free_map(t_map **map);

int					floorsqrt(int nb);
int					ft_valid(char *buf);

void				free_blocks(t_tetro_block **blocks, int t);

#endif
