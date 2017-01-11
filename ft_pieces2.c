/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 21:02:46 by dnelson           #+#    #+#             */
/*   Updated: 2017/01/11 13:41:37 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int		ft_place_16(char *tab, t_dance *tet)
{
	int	len;
	int	ofs;
	int	count;

	ofs = 0;
	len = 0;
	count = 0;
	ft_ofs_len(&ofs, &len, tab);
	while (count < 4)
	{
		if (tab[ofs] != '.')
			return (0);
		tab[ofs] = tet->label;
		if (count == 0)
			ofs += len - 1;
		else
			ofs++;
		count++;
	}
	return (1);
}

int		ft_place_5(char *tab, t_dance *tet)
{
	int	len;
	int	ofs;
	int	count;

	count = 0;
	ft_ofs_len(&ofs, &len, tab);
	while (count < 4)
	{
		if (tab[ofs] != '.')
			return (0);
		tab[ofs] = tet->label;
		if (count == 0)
			ofs += len - 2;
		else
			ofs++;
		count++;
	}
	return (1);
}

int		ft_place_19(char *tab, t_dance *tet)
{
	int	len;
	int	ofs;
	int	count;

	count = 0;
	ft_ofs_len(&ofs, &len, tab);
	while (count < 4)
	{
		if (tab[ofs] != '.')
			return (0);
		tab[ofs] = tet->label;
		if (count == 2)
			ofs += len - 1;
		else
			ofs++;
		count++;
	}
	return (1);
}
