/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 22:01:42 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/18 15:28:56 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

t_dance	*ft_newdance(char *tet)
{
	t_dance *res;

	res = (t_dance*)malloc(sizeof(t_dance));
	if (!res)
		return (NULL);
	ft_putstr("newdance malloc\n");
	res->tet = ft_strdup(tet);
	ft_putstr("strdup\n");
	res->right = res;
	ft_putstr("res->right = res\n");
	res->left = res;
	ft_putstr("res->left = res\n");
	return (res);
}

void	ft_newright(t_dance *head, char *tet)
{
	head->right = ft_newdance(tet);
	head->right->left = head;
	ft_putstr("just called for a newdance in newright\n");
}

void	ft_newleft(t_dance *head, char *tet)
{
	head->left = ft_newdance(tet);
	head->left->right = head;
	ft_putstr("just called for a newdance in newleft\n");
}

void	ft_printdance(t_dance *lst)
{
	t_dance *start;

	start = lst;
	while (lst->right != start)
	{
		ft_putstr(lst->tet);
		lst = lst->right;
	}
	ft_putstr(lst->tet);
}
