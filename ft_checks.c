/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:42:07 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/16 19:15:52 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headername.h"

int		test1(char **thing)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (thing[i][j] != '\0')
		{
			if (thing[i][j] == '#' && i > 0 && i < 3)
				if (thing[i - 1][j] == '#' || thing[i + 1][j] == '#')
					count++;
			if (thing[i][j] == '#' && j > 0 && j < 3)
				if (thing[i][j - 1] == '#' || thing[i][j + 1] == '#')
					count++;
			j++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}
