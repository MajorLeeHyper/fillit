/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:42:07 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/17 19:21:34 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_connection(char **tet)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (tet[i][j] != '\0')
		{
			if (tet[i][j] == '#' && i > 0 && i < 3)
				if (tet[i - 1][j] == '#' || tet[i + 1][j] == '#')
					count++;
			if (tet[i][j] == '#' && j > 0 && j < 3)
				if (tet[i][j - 1] == '#' || tet[i][j + 1] == '#')
					count++;
			j++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}
