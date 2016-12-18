/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:42:07 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/17 21:05:08 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

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
			if (tet[i][j] == '#')
			{
				count += (i > 0 && tet[i - 1][j] == '#') ? 1 : 0;
				count += (i < 3 && tet[i + 1][j] == '#') ? 1 : 0;
				count += (j > 0 && tet[i][j - 1] == '#') ? 1 : 0;
				count += (j < 3 && tet[i][j + 1] == '#') ? 1 : 0;
			}
			j++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		ft_issquare(char **tet)
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
			if (tet[i][j] == '#')
			{
				count += (i > 0 && tet[i - 1][j] == '#') ? 1 : 0;
				count += (i < 3 && tet[i + 1][j] == '#') ? 1 : 0;
				count += (j > 0 && tet[i][j - 1] == '#') ? 1 : 0;
				count += (j < 3 && tet[i][j + 1] == '#') ? 1 : 0;
			}
			j++;
		}
		i++;
	}
	if (count == 8)
		return (1);
	else
		return (0);
}
