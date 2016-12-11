/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:49:35 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/01 00:49:46 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhite(char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	if (c == ' ' || c == '\n' || c == '\t' || c == '	')
		return (1);
	return (0);
}
