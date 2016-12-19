/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 22:01:42 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/18 17:23:25 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

t_dance	*ft_newdance(char *tet, char let)
{
	t_dance *res;

	res = (t_dance*)malloc(sizeof(t_dance));
	if (!res)
		return (NULL);
	res->tet = ft_strdup(tet);
	res->right = NULL;
	res->left = NULL;
	res->label = let;
	return (res);
}

void	ft_newright(t_dance **start, char *tet, char let)
{
	t_dance *head;

	head = *start;
	head->right = ft_newdance(tet, let);
	head->right->left = head;
}

void	ft_newleft(t_dance **start, char *tet, char let)
{
	t_dance *head;

	head = *start;
	head->left = ft_newdance(tet, let);
	head->left->right = head;
}

void	ft_printdance(t_dance *lst)
{
	while (lst->right != NULL)
	{
		ft_putchar(lst->label);
		ft_putstr(lst->tet);
		lst = lst->right;
	}
		ft_putchar(lst->label);
	ft_putstr(lst->tet);
}

void	ft_makedance(t_dance **start, t_dance **end)
{
	t_dance *s;
	t_dance *e;

	s = *start;
	e = *end;
	e->right = s;
	s->left = e;
}

int		ft_countdance(t_dance *start)
{
	t_dance *cpy;
	int		count;

	cpy = start;
	count = 0;
	if (start)
	{
		count++;
		start = start->left;
	}
	while (start != cpy)
	{
		count++;
		start = start->left;
	}
	return (count);
}
