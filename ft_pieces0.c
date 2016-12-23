/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieces0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:43:22 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/22 16:38:50 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int		ft_place_square(char *tab, t_dance *tet)
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
	while (tab[len] != '\n')
		len++;
	len++;
	while (tab[offset] != '.')
		offset++;
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
