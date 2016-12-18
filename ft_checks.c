/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:42:07 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/17 20:22:47 by vyudushk         ###   ########.fr       */
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
				if (i != 0 && tet[i - 1][j] == '#')
				{
					count++;
					ft_putstr("column count++\n");
				}
				if (i != 3 && tet[i + 1][j] == '#')
				{
					ft_putstr("column count++\n");
					count++;
				}
				if (j != 0 && tet[i][j - 1] == '#')
				{
					count++;
					ft_putstr("row count++\n");
				}
				if (j != 3 && tet[i][j + 1] == '#')
				{
					ft_putstr("row count++\n");
					count++;
				}
			}
			j++;
		}
		i++;
	}
	if (count >= 6)
		return (1);
	return (0);
}
