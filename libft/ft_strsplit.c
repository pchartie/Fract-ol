/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:02:51 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:36:34 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	while (*s != '\0')
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			word++;
		}
		s++;
	}
	return (word);
}

static int	size_word(const char *s, char c)
{
	int size;

	size = 0;
	while (*s != c && *s != '\0')
	{
		size++;
		s++;
	}
	return (size);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		nb_word;
	int		i;

	i = 0;
	nb_word = count_word(s, c);
	tab = (char**)malloc(sizeof(char*) * nb_word + 1);
	if (!tab)
		return (NULL);
	while (i < nb_word)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char *)s, 0, size_word(s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + size_word(s, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
