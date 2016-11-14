/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:21:12 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:16:21 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char *src;
	char *dest;

	dest = (char *)s1;
	src = (char *)s2;
	if (n)
	{
		while (n != '\0')
		{
			*dest = *src;
			dest++;
			src++;
			if (*(src - 1) == c)
				return (dest);
			n--;
		}
	}
	return (NULL);
}
