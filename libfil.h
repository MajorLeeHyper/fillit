/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfil.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:37:50 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/17 19:32:55 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFIL_H
# define LIBFIL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

char			*ft_get_tetro(char *arg);
int				ft_connection(char **tet);

typedef struct	s_block
{
	int	coord[4][4];
	struct s_block	*next;
}				t_block;

#endif
