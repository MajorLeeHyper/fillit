/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:20:02 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/10 16:28:19 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> //TODO REMOVE
#include "libft.h"
#include "libfil.h"

int		main(int argc, char **argv)
{
	char	*buff;

	if (argc != 2)
		return (0);
	buff = ft_get_tetro(argv[1]);
	if (buff == 0)
		return (0);
	return (0);
}