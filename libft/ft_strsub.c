/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:10:25 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:37:48 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*tronc;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	tronc = (char*)malloc(sizeof(char) * (len) + 1);
	if (!tronc)
		return (NULL);
	while (i < start)
		i++;
	while (j < len)
	{
		tronc[j] = s[i];
		i++;
		j++;
	}
	tronc[j] = '\0';
	return (tronc);
}
