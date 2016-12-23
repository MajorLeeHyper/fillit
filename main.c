/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:20:02 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/23 13:40:38 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "libfil.h"

static int	ft_checkfull(char *tab)
{
	while (*tab)
	{
		if (*tab == '.')
			return (0);
		tab++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_dance	*lst;
	char	*tab;
	int		size;

	if (argc != 2)
	{
		ft_putendl("usage: program requires one file as an argument");
		return (0);
	}
	size = 0;
	lst = ft_get_tetro(argv[1]);
	tab = ft_maketable(lst, size);
	while (ft_countdance(lst))
	{
		if (ft_checkfull(tab) && ft_countdance(lst) >= 1)
		{
			size++;
			lst = ft_get_tetro(argv[1]);
			tab = ft_maketable(lst, size);
		}
		if (ft_place_tetro(tab, lst) == 1)
		{
			lst = ft_remove(lst);
			ft_convert_tab(tab, '0', '.');
			ft_putendl(tab); /*remember to remove before submit*/
		}
		else
		{
			ft_convert_one(tab, lst->label, '0');
			ft_putendl(tab);/*remember to remove before submit*/
		}
	}
	ft_putstr(tab);
	return (0);
}
