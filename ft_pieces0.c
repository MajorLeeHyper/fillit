/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:43:22 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/22 17:06:10 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int		ft_place_1(char *tab, t_dance *tet)
{
	int	offset;
	int	len;
	int	count;

	offset = 0;
	len = 0;
	count = 0;
	ft_ofs_len(&offset, &len, tab);
	while (count < 4)
	{
		if (tab[offset] != '.')
			return (0);
		tab[offset] = tet->label;
		if (count == 0 || count == 2)
			offset = offset + 1;
		else
			offset = offset - 1 + len;
		count++;
	}
	return (1);
}

int		ft_place_14_15(char *tab, t_dance *tet)
{
	int	offset;
	int	len;
	int	count;

	offset = 0;
	len = 0;
	count = 0;
	ft_ofs_len(&offset, &len, tab);
	if (tet->tet == 15)
		offset++;
	while (count < 4)
	{
		if (tab[offset] != '.')
			return (0);
		tab[offset] = tet->label;
		if (count == 0 || count == 2)
			offset = offset + len - 1;
		if (tet->tet == 14 || count == 1)
			offset++;
		count++;
	}
	return (1);
}

int		ft_place_3(char *tab, t_dance *tet)
{
	int	len;
	int	offset;
	int	count;

	len = 0;
	offset = 0;
	count = 0;
	ft_ofs_len(&offset, &len, tab);
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

int		ft_place_2(char *tab, t_dance *tet)
{
	int	ofs;

	ofs = 0;
	while (tab[ofs] != '.')
		ofs++;
	if (tab[ofs] == '.' && tab[ofs + 1] == '.' && tab[ofs + 2] == '.' &&
			tab[ofs + 3] == '.')
	{
		tab[ofs] = tet->label;
		tab[ofs + 1] = tet->label;
		tab[ofs + 2] = tet->label;
		tab[ofs + 3] = tet->label;
		return (1);
	}
	return (0);
}

int		ft_place_8_9_19(char *tab, t_dance *tet)
{
	int len;
	int	offset;
	int count;

	len = 0;
	offset = 0;
	count = 0;
	ft_ofs_len(&offset, &len, tab);
	if (tet->tet == 8 || tet->tet == 9 || tet->tet == 19)
	{
		if (tab[offset] != '.' || tab[offset + 1] != '.' ||
				tab[offset + 2] != '.')
			return (0);
		tab[offset] = tet->label;
		tab[offset + 1] = tet->label;
		tab[offset + 2] = tet->label;
		count += 3;
	}
	if (tet->tet == 9 && tab[offset + len] == '.')
		tab[offset + len] = tet->label;
	if (tet->tet == 19 && tab[offset + len + 1] == '.')
		tab[offset + len + 1] = tet->label;
	if (tet->tet == 8 && tab[offset + len + 2] == '.')
		tab[offset + len + 2] = tet->label;
	return (1);
}
