/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:07:55 by gvirga            #+#    #+#             */
/*   Updated: 2018/08/27 20:47:10 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_attached(char *buf, int i)
{
	int		link;

	link = 0;
	if (i < 15 && buf[i + 5] == '#')
		link++;
	if (i > 4 && buf[i - 5] == '#')
		link++;
	if (buf[i + 1] == '#')
		link++;
	if (i != 0 && buf[i - 1] == '#')
		link++;
	return (link);
}

static int		check_point_break(char *b, int i)
{
	if (i % 5 != 4 && i != 20)
	{
		if (b[i] == '.')
			return (1);
		else
			return (0);
	}
	else
	{
		if (b[i] != '\n')
			return (0);
	}
	return (1);
}

static int		check_hash(int *f_b, int *n_h, int i, t_tetri *t_l)
{
	if (t_l == NULL)
		return (0);
	(*n_h)++;
	if (*n_h == 1)
		*f_b = i;
	else if (*n_h > 1)
		fill_list(*f_b, *n_h, i, t_l);
	if (*n_h > 4)
		return (0);
	return (1);
}

int				check_piece(char *buf, t_tetri *tetris_list)
{
	int		i;
	int		nb_hash;
	int		first_bl;
	int		links;

	links = 0;
	first_bl = 0;
	i = -1;
	nb_hash = 0;
	while (buf[++i])
	{
		if (check_point_break(buf, i) != 0)
			continue;
		if (buf[i] == '#'
				&& check_hash(&first_bl, &nb_hash, i, tetris_list) != 0)
		{
			links += check_attached(buf, i);
			continue;
		}
		else
			return (0);
	}
	if (nb_hash != 4 || (links != 6 && links != 8))
		return (0);
	return (1);
}

int				n_f(t_tetri *t_l, int *nb_bytes, char *nb_tetris, int ret)
{
	*nb_bytes += ret;
	t_l->letter = *nb_tetris;
	(*nb_tetris)++;
	if (*nb_tetris - 'A' + 1 > 26)
		return (0);
	return (1);
}
