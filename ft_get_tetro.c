/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:52:22 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/11 15:14:13 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

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
