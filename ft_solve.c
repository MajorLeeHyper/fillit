/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:57:33 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/22 18:55:17 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int		ft_place_tetro(char *tab, t_dance *tet)
{
	if (tet->tet == 1)
		return (ft_place_1(tab, tet));
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
		return (ft_place_8_9_19(tab, tet));
	if (tet->tet == 14 || tet->tet == 15)
		return (ft_place_14_15(tab, tet));
	if (tet->tet == 17 || tet->tet == 18)
		return (ft_place_17_18(tab, tet));
	return (0);
}
