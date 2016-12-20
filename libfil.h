/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfil.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:37:50 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/19 17:39:45 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFIL_H
# define LIBFIL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

typedef struct	s_dance
{
	int				tet;
	char			label;
	struct s_dance	*right;
	struct s_dance	*left;
}				t_dance;

t_dance			*ft_get_tetro(char *arg);
int				ft_connection(char **tet);
t_dance			*ft_newdance(int tet, char let);
void			ft_newright(t_dance **start, int tet, char let);
void			ft_newleft(t_dance **start, int tet, char let);
void			ft_make_circle(t_dance *head);
void			ft_printdance(t_dance *lst);
void			ft_makedance(t_dance **start, t_dance **end);
int				ft_countdance(t_dance *start);
int				ft_tet_type(char *tet);
char			*ft_maketable(int size);
int				ft_find_tab_size(int x);

#endif
