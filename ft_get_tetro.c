/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:52:22 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/16 12:20:53 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

/*
** Will return 0 if tetromino is valid.
*/

int		ft_check_valid(char tet)
{
	int	n;

	if (tet[4] != '\n' || tet[9] != '\n' || tet[14] != '\n' || tet[19] != '\n')
		return (1);
	if (tet[20] != '\n')
		return (2);
	if (tet[20] != 0)
		return (3);
	n = 0;
	while (n != 19)
	{
		if (tet[n] != '.' || tet[n] != '#' || tet[n] != '\n')
			return (4);
		n++;
	}
	return (0);
}

char	*ft_get_tetro(char *arg)
{
	int		fd;
	char	*buff;

	buff = ft_strnew(22);
	if (buff == 0)
		return (0);
	fd = open(arg, O_RDONLY);
	while (read(fd, buff, 21))
	{
		ft_putstr(buff);
	}
	return (buff);
}
