/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:06:36 by lpersin           #+#    #+#             */
/*   Updated: 2018/09/07 14:39:39 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FILLIT_H
#	define FILLIT_H

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

#define BUF_SIZE 21

typedef struct		s_tetri
{
	char			coord[6];
	struct s_tetri	*next;
	char			letter;
}					t_tetri;
int					is_valid(char *map, char size, int pos, t_tetri *tetri);
t_tetri				*ft_lstinit();
void				fill_list(int f_b, int nb_hash, int i, t_tetri *t_l);
int					check_piece(char *buf, t_tetri *tetris_list);
int					n_f(t_tetri *t_l, int *nb_bytes, char *nb_tetris, int ret);
int					verif_file(char *file, t_tetri *tetri_list);

#	endif
