/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:52:22 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/23 17:47:12 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

static int		ft_check_valid(char *tet)
{
	int	n;
	int	count;
	
//	if (ft_strlen(tet) != 21)
//		if (ft_strlen(tet) != 20)
	//		return (6);
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

t_dance			*ft_get_tetro(char *arg)
{
	int		fd;
	char	*buff;
	t_dance *lst;
	t_dance *start;
	char	let;

	buff = ft_strnew(22);
	if (buff == 0)
		return (0);
	fd = open(arg, O_RDONLY);
	read(fd, buff, 21);
	if (ft_check_valid(buff) != 0)
		return (0);
	let = 'A';
	lst = ft_newdance(ft_tet_type(buff), let);
	start = lst;
	ft_bzero(buff, 22);
	while (read(fd, buff, 21))
	{
		let++;
		if (ft_check_valid(buff) != 0)
			return (0);
		ft_newright(&lst, ft_tet_type(buff), let);
		ft_bzero(buff, 22);
		lst = lst->right;
	}
	ft_makedance(&start, &lst);
	return (start);
}
