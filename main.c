/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:20:02 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/22 18:55:50 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "libfil.h"

int		main(int argc, char **argv)
{
	t_dance	*lst;
	char	*tab;

	if (argc != 2)
	{
		ft_putendl("usage: program requires one file as an argument");
		return (0);
	}
	lst = ft_get_tetro(argv[1]);
	tab = ft_maketable(lst);
	while (ft_countdance(lst) != 1)
	{
		ft_place_tetro(tab, lst);
		lst = ft_remove(lst);
	}
	ft_place_tetro(tab, lst);
	ft_putstr(tab);
	return (0);
}
