/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:20:02 by vyudushk          #+#    #+#             */
/*   Updated: 2017/01/11 14:02:46 by dnelson          ###   ########.fr       */
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

static char	*solver(int size, char *tab, char *str, t_dance *lst)
{
	int		tetros;

	tetros = ft_countdance(lst);
	while (tetros)
	{
		if (ft_checkfull(tab) && ft_countdance(lst) == tetros)
		{
			lst = ft_get_tetro(str);
			tab = ft_maketable(lst, ++size);
		}
		else if (ft_checkfull(tab) && ft_countdance(lst) != tetros)
		{
			tetros++;
			ft_convert_one(tab, (lst = lst->left)->label, '0');
		}
		if (ft_place_tetro(tab, lst) == 1)
		{
			lst = lst->right;
			tetros--;
			ft_convert_tab(tab, '0', '.');
		}
		else
			ft_convert_two(tab, lst->label, '0');
	}
	return (tab);
}

int			main(int argc, char **argv)
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
	if (lst == 0)
	{
		write(1, "error\n", 6);
		return (1);
	}
	tab = ft_maketable(lst, size);
	ft_putstr(solver(size, tab, argv[1], lst));
	return (0);
}
