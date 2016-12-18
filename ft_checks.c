/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:42:07 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/17 20:00:15 by vyudushk         ###   ########.fr       */
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
				if (tet[i - 1][j] == '#' && i > 0)
				{
					count++;
					ft_putstr("column count++\n");
				}
				if (tet[i + 1][j] == '#' && i < 3)
				{
					ft_putstr("column count++\n");
					count++;
				}
				if (tet[i][j - 1] == '#' && j > 0)
				{
					count++;
					ft_putstr("row count++\n");
				}
				if (tet[i][j + 1] == '#'&& j < 3)
				{
					ft_putstr("row count++\n");
					count++;
				}
			}
			j++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}
