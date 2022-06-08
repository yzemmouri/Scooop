/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:43:10 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:10:23 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t n_bytes)
{
	size_t	i;
	char	*p_mem;

	i = 0;
	p_mem = (char *)p;
	while (i < n_bytes)
	{
		p_mem[i] = c;
		i++;
	}
	return (p);
}
