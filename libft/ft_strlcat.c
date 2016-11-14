/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:10:24 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:46:33 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i;
	int s1_end;

	i = 0;
	while (dest[i] && (unsigned int)i < size)
		i++;
	s1_end = i;
	while (src[i - s1_end] && (unsigned int)i < size - 1)
	{
		dest[i] = src[i - s1_end];
		i++;
	}
	if ((unsigned int)s1_end < size)
		dest[i] = '\0';
	return (s1_end + ft_strlen(src));
}
