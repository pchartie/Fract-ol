/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:28:55 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:19:21 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char *tmp;

	if (!n)
		return (s1);
	tmp = ft_memalloc(n);
	tmp = ft_memcpy(tmp, s2, n);
	s1 = ft_memcpy(s1, tmp, n);
	free(tmp);
	return (s1);
}
