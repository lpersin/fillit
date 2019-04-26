/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:05:57 by gvirga            #+#    #+#             */
/*   Updated: 2018/08/27 21:27:09 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		display_map(char *map, char size)
{
	unsigned int	count;
	unsigned char	i;

	count = 0;
	i = size;
	while (i)
	{
		write(1, (void*)map + count, size);
		ft_putchar('\n');
		count += size;
		i--;
	}
}

static void		display_error(void)
{
	ft_putstr("error");
}

static void		solver(t_tetri *head, char letter)
{
	char	size;
	char	*map;

	size = ft_sqrtup((letter - 'A' + 1) * 4);
	map = ft_strnew((size_t)size * size);
	ft_memset(map, '.', size * size);
	while (!is_valid(map, size, 0, head))
	{
		size++;
		free(map);
		map = ft_strnew((size_t)size * size);
		ft_memset(map, '.', size * size);
	}
	display_map(map, size);
}

static void		display_use_error(void)
{
	ft_putstr("usage: ./fillit file");
}

int				main(int ac, char **av)
{
	t_tetri	*tetri_list;
	t_tetri *head;

	if (ac > 2)
	{
		display_use_error();
		return (0);
	}
	tetri_list = ft_lstinit();
	head = tetri_list;
	if (tetri_list != NULL)
	{
		if ((verif_file(av[1], tetri_list)) != 0)
		{
			while (tetri_list->next->next)
				tetri_list = tetri_list->next;
			free(tetri_list->next);
			tetri_list->next = NULL;
			solver(head, tetri_list->letter);
		}
		else
			display_error();
	}
	return (0);
}
