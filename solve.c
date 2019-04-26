/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:34:20 by lpersin           #+#    #+#             */
/*   Updated: 2018/08/27 20:34:25 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		valid_pos(char *map, int pos, char size, int *dst_coord)
{
	unsigned char	i;

	i = 0;
	if (map[pos] == '.')
	{
		while (i < 3)
		{
			if (dst_coord[i] > size * size
					|| (map[dst_coord[i]] != '.'))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

static void		insert_char(char *map, int pos, char letter, int *dst_coord)
{
	unsigned char i;

	i = 0;
	map[pos] = letter;
	while (i < 3)
	{
		map[dst_coord[i]] = letter;
		i++;
	}
}

static void		get_dst_coord(int pos, char size,
							t_tetri *tetri, int *dst_coord)
{
	unsigned char	i;
	unsigned char	j;

	i = 0;
	j = 0;
	while (i < 5)
	{
		dst_coord[j] = pos + tetri->coord[i] + (tetri->coord[i + 1] * size);
		i += 2;
		j++;
	}
}

static int		valid_shape(t_tetri *tetri, int *dst_coord, int pos, char size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < 5)
	{
		if (tetri->coord[i + 1] + (pos / size) != (dst_coord[j] / size))
			return (0);
		i += 2;
		j++;
	}
	return (1);
}

int				is_valid(char *map, char size, int pos, t_tetri *tetri)
{
	int dst_coord[3];

	if (!tetri)
		return (1);
	while (pos < size * size)
	{
		get_dst_coord(pos, size, tetri, dst_coord);
		if (valid_pos(map, pos, size, dst_coord)
					&& valid_shape(tetri, dst_coord, pos, size))
		{
			insert_char(map, pos, tetri->letter, dst_coord);
			if (is_valid(map, size, 0, tetri->next))
				return (1);
			insert_char(map, pos, '.', dst_coord);
		}
		pos++;
	}
	return (0);
}
