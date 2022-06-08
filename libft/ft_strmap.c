/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:36:26 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:13:15 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		lent;
	char	*str;
	char	*src;

	i = 0;
	if (s)
	{
		src = (char *)s;
		lent = ft_strlen(s) + 1;
		str = (char *)malloc(sizeof(char) * lent);
		if (!(str))
			return (NULL);
		while (src[i] != '\0')
		{
			str[i] = f(src[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
