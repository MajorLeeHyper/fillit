/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 22:01:42 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/17 22:47:51 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

t_dance	*ft_newdance(char *tet)
{
	t_dance *res;

	res = (t_dance*)malloc(sizeof(t_dance));
	if (!res)
		return (NULL);
	ft_putstr("just created a new link in newdance\n");
	res->tet = ft_strdup(tet);
	return (res);
}

void	ft_newright(t_dance *head, char *tet)
{
	while (head->right != NULL)
		head = head->right;
	head->right = ft_newdance(tet);
	ft_putstr("just called for a newdance in newright\n");
}

void	ft_newleft(t_dance *head, char *tet)
{
	while (head->left != NULL)
		head = head->left;
	head->left = ft_newdance(tet);
	ft_putstr("just called for a newdance in newleft\n");
}

void	ft_make_circle(t_dance *head)
{
	t_dance *start;

	start = head;
	while (head->right != NULL)
		head = head->right;
	if (head->right == NULL)
	{
		head->right = start;
		start->left = head;
	}
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
