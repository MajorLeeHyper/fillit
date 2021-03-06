/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:52:22 by vyudushk          #+#    #+#             */
/*   Updated: 2017/01/11 14:26:46 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

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

static char		*set_up_buff(char *arg, int *fd, char *let)
{
	char *buff;

	buff = ft_strnew(22);
	if (buff == 0)
		return (0);
	*fd = open(arg, O_RDONLY);
	read(*fd, buff, 21);
	if (ft_check_valid(buff) != 0)
		return (0);
	*let = 'A';
	return (buff);
}

static t_dance	*set_up_dance(char *buff, char *let, int *flag)
{
	t_dance *lst;

	lst = ft_newdance(ft_tet_type(buff), *let);
	*flag = 0;
	if (buff[20] == '\0')
		*flag = 1;
	ft_bzero(buff, 22);
	return (lst);
}

t_dance			*ft_get_tetro(char *arg)
{
	int		fd_and_flag[2];
	char	*buff;
	t_dance *lst;
	t_dance *start;
	char	let;

	buff = set_up_buff(arg, &fd_and_flag[0], &let);
	if (buff == 0)
		return (0);
	lst = set_up_dance(buff, &let, &fd_and_flag[1]);
	start = lst;
	while (read(fd_and_flag[0], buff, 21) && let++ < 'Z')
	{
		if (buff[20] == '\0')
			fd_and_flag[1] = 1;
		if (ft_check_valid(buff) != 0)
			return (0);
		ft_newright(&lst, ft_tet_type(buff), let);
		ft_bzero(buff, 22);
		lst = lst->right;
	}
	ft_makedance(&start, &lst);
	if (fd_and_flag[1] == 1)
		return (start);
	return (0);
}
