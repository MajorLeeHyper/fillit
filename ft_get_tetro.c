/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:52:22 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/18 15:36:42 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"
#include <stdio.h> //TODO remove

/*
** Will return 0 if tetromino is valid. Does not check for individual tetromino
*/

/*
t_block	*ft_get_block(char *tet)
{
	t_block *start;
	int	x;
	int	y;

	start = (t_block*)malloc(sizeof(t_block));
	if (start == 0)
		return (0);
	x = 0;
	y = 0;
	while (*tet)
	{
		if (*tet == '#')
		{
			start->coord
		}
		if (*tet == '\n')
		{
			x = 0;
			y++;
		}
		tet++;
	}
}
*/

static int		ft_check_valid(char *tet)
{
	int	n;
	int	count;

	if (tet[4] != '\n' || tet[9] != '\n' || tet[14] != '\n' || tet[19] != '\n')
		return (1);
	if (tet[20] != '\n' && tet[20] != 0)
		return (2);
	n = 0;
	count = 0;
	while (n != 19)
	{
		if (tet[n] != '.' && tet[n] != '#' && tet[n] != '\n')
			return (3);
		if (tet[n] == '#')
			count++;
		n++;
	}
	if (count != 4)
		return (4);
	if (ft_connection(ft_strsplit(tet, '\n')) != 1)
		return (5);
	return (0);
}

char	*ft_get_tetro(char *arg)
{
	int		fd;
	char	*buff;
//	t_dance *lst;

	buff = ft_strnew(22);
	if (buff == 0)
		return (0);
	fd = open(arg, O_RDONLY);
//	read(fd, buff, 21);
//	lst = ft_newdance(buff);
	while (read(fd, buff, 21))
	{
		if (ft_check_valid(buff) == 0)
			ft_putstr("valid!\n");
		ft_putstr(buff);
		ft_bzero(buff, 22);
//		ft_newright(lst, buff);
	}
	return (buff);
}
