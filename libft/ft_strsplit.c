/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:54:19 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:30:34 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_words(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (j == 1 && *s == c)
			j = 0;
		if (j == 0 && *s != c)
		{
			j = 1;
			i++;
		}
		s++;
	}
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	int		word;
	t_2d	p;
	int		start;
	char	**tab;

	if (s == 0 || c == 0)
		return (NULL);
	word = ft_count_words(s, c);
	tab = (char **)malloc((sizeof(char *) * (word + 1)));
	if (!(tab))
		return (NULL);
	p.i = 0;
	p.j = -1;
	while (++p.j < word)
	{
		while (s[p.i] && s[p.i] == c)
			p.i++;
		start = p.i;
		while (s[p.i] && s[p.i] != c)
			p.i++;
		tab[p.j] = ft_strsub(s, start, p.i - start);
		p.i++;
	}
	tab[p.j] = NULL;
	return (tab);
}
