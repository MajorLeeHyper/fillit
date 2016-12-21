/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:57:33 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/20 16:54:39 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

void	ft_place_tetro(char *tab, int tet)
{
	int	track;
	int i;
	int	count;

	track = 1;
	count = 0;
	i = 0;
	tet = 0;
	while (tab[track] != '.')
		track++;
	tab[track] = '#';
	count++;
	while (count != 4)
	{
		while (tab[track + i] != '\n')
			i++;
		i++;
		while (tab[track + i])
		tab[i + track] = '#';
		count++;
	}
}

/*
char	*ft_solve(t_dance *lst, char *tab)
{
}*/
