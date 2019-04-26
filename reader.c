/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:08:22 by gvirga            #+#    #+#             */
/*   Updated: 2018/08/27 20:47:31 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		read_file(int fd, t_tetri *tetri_list)
{
	char	nb_tetris;
	int		ret;
	char	buf[BUF_SIZE];
	int		nb_bytes;

	nb_tetris = 'A';
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		if (check_piece(buf, tetri_list) == 0
				|| n_f(tetri_list, &nb_bytes, &nb_tetris, ret) == 0)
			return (0);
		else
		{
			tetri_list->next = ft_lstinit();
			tetri_list = tetri_list->next;
		}
	}
	if (ret == -1 || nb_bytes == 0)
		return (0);
	if (nb_tetris - 'A' > 1 && (nb_bytes - 20) % 21 != 0)
		return (0);
	if (nb_tetris - 'A' == 1 && nb_bytes % 20 != 0)
		return (0);
	return (1);
}

int				verif_file(char *file, t_tetri *tetri_list)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		if (read_file(fd, tetri_list) != 0)
			return (1);
	}
	close(fd);
	return (0);
}
