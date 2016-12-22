/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:58:12 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/21 18:07:44 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int			ft_connection(char **tet)
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

static void	ft_increment(size_t *i, size_t *j)
{
	*i = *i + 1;
	*j = *j + 1;
}

static char	*ft_trim(char *just_tet)
{
	size_t	j;

	j = ft_strlen(just_tet) - 1;
	while (just_tet[j] == '.' || just_tet[j] == '\n')
	{
		just_tet[j] = '\0';
		j--;
	}
	return (just_tet);
}

static char	*ft_simplify_tet(char *tet)
{
	size_t	i;
	size_t	j;
	char	*condenced;

	i = 0;
	condenced = ft_strdup(tet);
	while (condenced[i] == '.' || condenced[i] == '\n')
		i++;
	j = i;
	i = 0;
	while (tet[j] != '\0')
	{
		if (tet[j] == '\n')
		{
			condenced[i] = tet[j + 1];
			i++;
			j = j + 2;
		}
		condenced[i] = tet[j];
		if (condenced[i] != '\0' && tet[j] != '\0')
			ft_increment(&i, &j);
	}
	return (ft_trim(condenced));
}

int			ft_tet_type(char *tet)
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
	i += (ft_strcmp(small, "##...##") == 0 ? 13 : 0);
	i += (ft_strcmp(small, "#...##...#") == 0 ? 14 : 0);
	i += (ft_strcmp(small, "#..##..#") == 0 ? 15 : 0);
	i += (ft_strcmp(small, "#..###") == 0 ? 16 : 0);
	i += (ft_strcmp(small, "#..##...#") == 0 ? 17 : 0);
	i += (ft_strcmp(small, "#...##..#") == 0 ? 18 : 0);
	i += (ft_strcmp(small, "###..#") == 0 ? 19 : 0);
	return (i);
}
