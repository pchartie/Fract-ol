/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 22:40:32 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:25:44 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	i = 0;
	tmps1 = (unsigned char*)s1;
	tmps2 = (unsigned char*)s2;
	while (tmps1[i] && tmps2[i])
	{
		if (tmps1[i] == tmps2[i])
			i++;
		else
			return (tmps1[i] - tmps2[i]);
	}
	return (tmps1[i] - tmps2[i]);
}
