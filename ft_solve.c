/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:57:33 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/22 16:21:59 by vyudushk         ###   ########.fr       */
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
	if (tet->tet == 9 && tab[offset + len] == '.')
		tab[offset + len] = tet->label;
	if (tet->tet == 19 && tab[offset + len + 1] == '.')
		tab[offset + len + 1] = tet->label;
	if (tet->tet == 8 && tab[offset + len + 2] == '.')
		tab[offset + len + 2] = tet->label;
	return (1);
}

int		ft_place_4_5_16(char *tab, t_dance *tet)
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
	if (tet->tet == 4 && tab[offset] == '.')
		tab[offset] = tet->label;
	if (tet->tet == 16 && tab[offset + 1] == '.')
		tab[offset + 1] = tet->label;
	if (tet->tet == 5 && tab[offset + 2] == '.')
		tab[offset + 2] = tet->label;
	if (tet->tet == 4 || tet->tet == 5 || tet->tet == 16)
	{
		if (tab[offset + len] != '.' || tab[offset + len + 1] != '.' || tab[offset + len + 2] != '.')
			return (0);
		tab[offset + len] = tet->label;
		tab[offset + len + 1] = tet->label;
	   	tab[offset + len + 2] = tet->label;
		count += 3;
	}
	return (1);
}

int		ft_place_2(char *tab, t_dance *tet)
{
	int	ofs;

	ofs = 0;
	while (tab[ofs] != '.')
		ofs++;
	if (tab[ofs] == '.' && tab[ofs + 1] == '.' && tab[ofs + 2] == '.' && tab[ofs + 3] == '.')
	{
		tab[ofs] = tet->label;
		tab[ofs + 1] = tet->label;
		tab[ofs + 2] = tet->label;
		tab[ofs + 3] = tet->label;
		return (1);
	}
	return (0);
}

int		ft_place_6_10(char *tab, t_dance *tet)
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
	else if (tab[offset - (len * 3) + 1] != '.' || tab[offset - len + 1] != '.')
		return (0);
	return (1);
}

int		ft_place_7_11(char *tab, t_dance *tet)
{
	int	len;
	int	ofs;
	int	count;

	len = 0;
	ofs = 0;
	count = 0;
	while (tab[len] != '\n')
		len++;
	len++;
	while (tab[ofs] != '.')
		ofs++;
	if (tet->tet == 11 && tab[ofs] == '.')
		tab[ofs] = tet->label;
	else if (tet->tet == 7 && tab[ofs + (len * 3)] == '.')
		tab[ofs + (len * 2)] = tet->label;
	else if (tab[ofs] != '.' || tab[ofs] != '.')
		return (0);
	ofs++;
	while (count < 3)
	{
		if (tab[ofs] != '.')
			return (0);
		tab[ofs] = tet->label;
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

		offset = 0;
		len = 0;
		count = 0;
		while (tab[len] != '\n')
			len++;
		len++;
		while (tab[offset] != '.')
			offset++;
		if (tet->tet == 12)
			offset++;
		while (count < 4)
		{
			if (tab[offset] != '.')
				return (0);
			tab[offset] = tet->label;
			if ((count == 0 || count == 2) && tet->tet == 12)
				offset = offset + 1;
			else if (tet->tet == 12)
				offset = offset  - 2 + len;
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

	ofs = 0;
	len = 0;
	count = 0;
	while (tab[len] != '\n')
		len++;
	len++;
	while (tab[ofs] != '.')
		ofs++;
	if (tet->tet == 17)
		ofs++;
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
	else if (tet->tet == 18 && tab[ofs + 1] != '.')
		return (0);
	if (tet->tet == 17 && tab[ofs - 1] == '.')
		tab[ofs - 1] = tet->label;
	else if (tet->tet == 17 && tab[ofs - 1] != '.')
		return (0);
	return (1);
}

int		ft_place_tetro(char *tab, t_dance *tet)
{
	if (tet->tet == 1)
		return (ft_place_square(tab, tet));
	if (tet->tet == 2)
		return (ft_place_2(tab, tet));
	if (tet->tet == 3)
		return (ft_place_3(tab, tet));
	if (tet->tet == 4 || tet->tet == 5 || tet->tet == 16)
		return (ft_place_4_5_16(tab, tet));
	if (tet->tet == 6 || tet->tet == 10)
		return (ft_place_6_10(tab, tet));
	if (tet->tet == 7 || tet->tet == 11)
		return (ft_place_7_11(tab, tet));
	if (tet->tet == 12 || tet->tet == 13)
		return (ft_place_12_13(tab, tet));
	if (tet->tet == 9 || tet->tet == 8 || tet->tet == 19)
		return (ft_place_9_8_19(tab, tet));
	if (tet->tet == 17 || tet->tet == 18)
		return (ft_place_17_18(tab, tet));
	return (0);
}
