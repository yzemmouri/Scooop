/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:34:33 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:23:58 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_tabnew_two(size_t x, size_t y)
{
	size_t	i;
	int		**tab;

	i = 0;
	tab = (int **)malloc(sizeof(tab) * y);
	if (!(tab))
		return (NULL);
	while (i < y)
	{
		tab[i] = (int *)malloc(sizeof(int) * x);
		if (!(tab))
			return (NULL);
		i++;
	}
	return (tab);
}
