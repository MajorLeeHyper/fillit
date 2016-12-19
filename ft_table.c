/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:30:49 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/18 18:48:53 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_maketable(int size)
{
	char	**table;
	int		i;

	table = (char**)malloc(sizeof(char) * size + 1);
	if (table == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		table[i] = (char*)malloc(sizeof(char) * size + 1);
		i++;
	}
	return (table);
}

int		ft_find_tab_size(int x)
{
	int	i;

	i = 0;
	while (i < 46341)
	{
		if (i * i >= x)
			return(i);
		i++;
	}
	return (0);
}
