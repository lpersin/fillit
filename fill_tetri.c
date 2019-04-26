/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:59:41 by gvirga            #+#    #+#             */
/*   Updated: 2018/08/27 16:12:22 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_lstinit(void)
{
	t_tetri *node;

	node = (t_tetri*)malloc(sizeof(*node));
	node->next = NULL;
	return (node);
}

void	fill_list(int first_bl, int nb_hash, int i, t_tetri *tetris_list)
{
	if (nb_hash == 2)
	{
		tetris_list->coord[0] = (i % 5) - (first_bl % 5);
		tetris_list->coord[1] = (i / 5) - (first_bl / 5);
	}
	else if (nb_hash == 3)
	{
		tetris_list->coord[2] = (i % 5) - (first_bl % 5);
		tetris_list->coord[3] = (i / 5) - (first_bl / 5);
	}
	else if (nb_hash == 4)
	{
		tetris_list->coord[4] = (i % 5) - (first_bl % 5);
		tetris_list->coord[5] = (i / 5) - (first_bl / 5);
	}
}
