/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:10:24 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:35:03 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *current;

	current = (char *)s + ft_strlen(s);
	while (*current != c)
	{
		if (current == s)
			return (NULL);
		current--;
	}
	return (current);
}
