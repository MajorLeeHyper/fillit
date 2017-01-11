/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 16:54:22 by dnelson           #+#    #+#             */
/*   Updated: 2017/01/11 13:41:13 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int		ft_place_4_5_16(char *tab, t_dance *tet)
{
	int len;
	int	offset;
	int count;

	if (tet->tet == 5)
		return (ft_place_5(tab, tet));
	if (tet->tet == 16)
		return (ft_place_16(tab, tet));
	count = 0;
	ft_ofs_len(&offset, &len, tab);
	while (count < 4)
	{
		if (tab[offset] != '.')
			return (0);
		tab[offset] = tet->label;
		if (count == 0)
			offset += len;
		else
			offset++;
		count++;
	}
	return (1);
}

int		ft_place_6_10(char *tab, t_dance *tet)
{
	int len;
	int	offset;
	int	count;

	count = 0;
	ft_ofs_len(&offset, &len, tab);
	while (count < 3)
	{
		if (tab[offset] != '.')
			return (0);
		tab[offset] = tet->label;
		offset = offset + len;
		count++;
	}
	if (tet->tet == 10 && (tab[offset - (len * 3) + 1] == '.'))
		tab[offset - (len * 3) + 1] = tet->label;
	else if (tet->tet == 6 && tab[offset - len + 1] == '.')
		tab[offset - len + 1] = tet->label;
	else if (tab[offset - (len * 3) + 1] != '.' ||
			tab[offset - len + 1] != '.')
		return (0);
	return (1);
}

int		ft_place_7_11(char *tab, t_dance *tet)
{
	int	len;
	int	ofs;
	int	count;

	count = 0;
	ft_ofs_len(&ofs, &len, tab);
	if (tet->tet == 11 && tab[ofs] == '.')
	{
		tab[ofs++] = tet->label;
		count++;
	}
	while (count < 4)
	{
		if (tab[ofs] != '.')
			return (0);
		tab[ofs] = tet->label;
		if (count == 1 && tet->tet == 7)
			ofs = ofs + len - 1;
		else if (count == 2 && tet->tet == 7)
			ofs++;
		else
			ofs = ofs + len;
		count++;
	}
	return (1);
}

int		ft_place_12_13(char *tab, t_dance *tet)
{
	int	offset;
	int	len;
	int	count;

	count = 0;
	ft_ofs_len(&offset, &len, tab);
	while (count < 4)
	{
		if (tab[offset] != '.')
			return (0);
		tab[offset] = tet->label;
		if ((count == 0 || count == 2) && tet->tet == 12)
			offset = offset + 1;
		else if (tet->tet == 12)
			offset = offset - 2 + len;
		else if ((count == 0 || count == 2) && tet->tet == 13)
			offset = offset + 1;
		else if (tet->tet == 13)
			offset = offset + len;
		count++;
	}
	return (1);
}

int		ft_place_17_18(char *tab, t_dance *tet)
{
	int ofs;
	int len;
	int count;

	count = 0;
	ft_ofs_len(&ofs, &len, tab);
	while (count < 3)
	{
		if (tab[ofs] != '.')
			return (0);
		tab[ofs] = tet->label;
		ofs = ofs + len;
		count++;
	}
	ofs = ofs - len * 2;
	if (tet->tet == 18 && tab[ofs + 1] == '.')
		tab[ofs + 1] = tet->label;
	else if (tet->tet == 17 && tab[ofs - 1] == '.')
		tab[ofs - 1] = tet->label;
	else if ((tet->tet == 18 && tab[ofs + 1] != '.') ||
			(tet->tet == 17 && tab[ofs - 1] != '.'))
		return (0);
	return (1);
}
