/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:20:02 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/19 17:42:48 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> //TODO REMOVE
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
	ft_printdance(lst);
	ft_putnbr(ft_countdance(lst));
	tab = (ft_maketable(ft_find_tab_size(ft_countdance(lst))));
	ft_putchar('\n');
	ft_putstr(tab);
	return (0);
}
