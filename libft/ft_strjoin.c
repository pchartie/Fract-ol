/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 22:32:46 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:29:40 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	size_s1;
	unsigned int	size_s2;
	unsigned int	i;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	i = 0;
	str = (char*)malloc(sizeof(char) * size_s1 + size_s2 + 1);
	if (!str)
		return (NULL);
	while (i < size_s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (i < size_s1 + size_s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
