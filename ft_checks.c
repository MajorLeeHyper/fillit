/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:42:07 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/18 17:39:23 by dnelson          ###   ########.fr       */
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
	return (0);
}

char	*ft_simplify_tet(char *tet)
{
	size_t	i;
	char	*condenced;
	size_t	j;

	i = 0;
	condenced = ft_strdup(tet); 
	while (*tet)
	{
		if (*tet == '\n')
		{
			condenced[i] = *tet + 1;
			i++;
		}
		if (condenced[i] != '\0')
			i++;
		tet++;
	}
	j = ft_strlen(condenced);
	while (i < j)
		condenced[i] = '\0';
	return (condenced);
}

int		ft_tet_type(char *tet)
{
	int		i;
	char	*small;

	i = 0;
	small = ft_simplify_tet(tet);
	i += (ft_strcmp(small, "##..##") == 0 ? 1 : 0);
	i += (ft_strcmp(small, "####") == 0 ? 2 : 0);
	i += (ft_strcmp(small, "#...#...#...#") == 0 ? 3 : 0);
	i += (ft_strcmp(small, "#...###") == 0 ? 4 : 0);
	i += (ft_strcmp(small, "#.###") == 0 ? 5 : 0);
	i += (ft_strcmp(small, "#...#...##") == 0 ? 6 : 0);
	i += (ft_strcmp(small, "#...#..##") == 0 ? 7 : 0);
	i += (ft_strcmp(small, "###...#") == 0 ? 8 : 0);
	i += (ft_strcmp(small, "###.#") == 0 ? 9 : 0);
	i += (ft_strcmp(small, "##..#...#") == 0 ? 10 : 0);
	i += (ft_strcmp(small, "##...#...#") == 0 ? 11 : 0);
	i += (ft_strcmp(small, "##.##") == 0 ? 12 : 0);
	i += (ft_strcmp(small, "#...##...#") == 0 ? 13 : 0);
	i += (ft_strcmp(small, "#...##...#") == 0 ? 14 : 0);
	i += (ft_strcmp(small, "#..##..#") == 0 ? 15 : 0);
	i += (ft_strcmp(small, "#..###") == 0 ? 16 : 0);
	i += (ft_strcmp(small, "#..##...#") == 0 ? 17 : 0);
	i += (ft_strcmp(small, "#...##..#") == 0 ? 18 : 0);
	i += (ft_strcmp(small, "###..#") == 0 ? 19 : 0);
	return (i);
}
