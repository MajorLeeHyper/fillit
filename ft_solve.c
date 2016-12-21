/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:57:33 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/20 17:49:16 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

static int	ft_place_3(char *tab, t_dance *tet)
{
	int len;
	int	offset;
	int	count;

	len = 0;
	offset = 0;
	count = 0;
	while (tab[len] != '\n')
		len++;
	len++;
	while (tab[offset] != '.')
		offset++;
	while (count < 4)
	{
		if (tab[offset] != '.')
			return (0);
		tab[offset] = tet->label;
		offset = offset + len;
		count++;
	}
	return (1);
}

int		ft_place_9_8_19(char *tab, t_dance *tet)
{
	int len;
	int	offset;
	int count;

	len = 0;
	offset = 0;
	count = 0;
	while (tab[len] != '\n')
		len++;
	len++;
	while (tab[offset] != '.')
		offset++;
	if (tet->tet == 8 || tet->tet == 9 || tet->tet == 19)
	{
		if (tab[offset] != '.' || tab[offset + 1] != '.' || tab[offset + 2] != '.')
			return (0);
		tab[offset] = tet->label;
		tab[offset + 1] = tet->label;
	   	tab[offset + 2] = tet->label;
		count += 3;
	}
	if (tet->tet == 9)
		tab[offset + len] = tet->label;
	if (tet->tet == 19)
		tab[offset + len + 1] = tet->label;
	if (tet->tet == 8)
		tab[offset + len + 2] = tet->label;
	return (1);
}

int		ft_place_tetro(char *tab, t_dance *tet)
{
	if (tet->tet == 3)
		return (ft_place_3(tab, tet));
	if (tet->tet == 9 || tet->tet == 8 || tet->tet == 19)
		return (ft_place_9_8_19(tab, tet));
	return (0);
}

/*
char	*ft_solve(t_dance *lst, char *tab)
{
}*/
