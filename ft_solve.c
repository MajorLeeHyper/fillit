/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:57:33 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/20 17:12:47 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int		ft_place_tetro(char *tab, t_dance *tet)
{
	int	offset;
	int len;
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
		offset = offset + len;
		count++;
	}
	return (1);
}

/*
char	*ft_solve(t_dance *lst, char *tab)
{
}*/
