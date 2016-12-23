/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfil.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:37:50 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/22 16:50:18 by vyudushk         ###   ########.fr       */
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
char			*ft_maketable(t_dance *lst);
int				ft_place_tetro(char *tab, t_dance *tet);

int				ft_place_1(char *tab, t_dance *tet);
int				ft_place_2(char *tab, t_dance *tet);
int				ft_place_3(char *tab, t_dance *tet);
int				ft_place_4_5_16(char *tab, t_dance *tet);
int				ft_place_6_10(char *tab, t_dance *tet);
int				ft_place_7_11(char *tab, t_dance *tet);
int				ft_place_12_13(char *tab, t_dance *tet);
int				ft_place_8_9_19(char *tab, t_dance *tet);
int				ft_place_14_15(char *tab, t_dance *tet);
int				ft_place_17_18(char *tab, t_dance *tet);

void			ft_ofs_len(int *ofs, int *len, char *tab);

#endif
