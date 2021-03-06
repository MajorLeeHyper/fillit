/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 10:29:03 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/04 22:46:13 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*hold;
	size_t	i;

	hold = s;
	i = 0;
	while (i < n)
	{
		hold[i] = c;
		i++;
	}
	return (hold);
}
