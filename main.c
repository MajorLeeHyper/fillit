/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:20:02 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/22 20:16:51 by dnelson          ###   ########.fr       */
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
	while (ft_countdance(lst))
	{
		if (ft_place_tetro(tab, lst) == 1)
		{
			lst = ft_remove(lst);
			ft_convert_tab(tab, '0', '.');
		}
		else
			ft_convert_tab(tab, lst->label, '0');
	}
	ft_putstr(tab);
	return (0);
}
