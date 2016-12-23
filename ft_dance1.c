/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dance1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:28:19 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/22 21:29:36 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

t_dance		*ft_remove(t_dance *x)
{
	if (ft_countdance(x) == 1)
	{
		x = 0;
		return (NULL);
	}
	x->left->right = x->right;
	x->right->left = x->left;
	return (x->right);
}

t_dance		*ft_replace(t_dance *x)
{
	x->left->right = x;
	x->right->left = x;
	return (x);
}
