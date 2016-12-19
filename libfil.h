/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfil.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:37:50 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/18 17:24:05 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFIL_H
# define LIBFIL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

typedef struct s_dance
{
	char	*tet;
	char	label;
	struct s_dance	*right;
	struct s_dance	*left;
}				t_dance;

char *ft_get_tetro(char *arg);
int				ft_connection(char **tet);
t_dance *ft_newdance(char *tet, char let);
void    ft_newright(t_dance **start, char *tet, char let);
void    ft_newleft(t_dance **start, char *tet, char let);
void    ft_make_circle(t_dance *head);
void	ft_printdance(t_dance *lst);
void	ft_makedance(t_dance **start, t_dance **end);
int		ft_countdance(t_dance *start);

#endif
