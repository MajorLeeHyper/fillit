/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:30:49 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/19 17:56:22 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

char	*ft_maketable(int size)
{
	char	*tab;
	int		n;

	tab = (char*)malloc(sizeof(char) * ((size) * size));
	if (tab == 0)
		return (NULL);
	ft_memset(tab, '.', ((size + 1) * size) + 1);
	tab[((size + 1) * size) + 1] = 0;
	n = 0;
	while (tab[n] != 0)
	{
		if (n % (size + 1) == 0)
			tab[n] = '\n';
		n++;
	}
	return (tab);
}

int		ft_find_tab_size(int x)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 4 * x;
	while (i < 46341)
	{
		if (i * i >= spaces)
			return(i);
		i++;
	}
	return (0);
}
