/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:24:01 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:14:29 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	int		lent;
	char	*str;
	char	*src;

	i = 0;
	j = 0;
	if (s)
	{
		src = (char *)s;
		lent = ft_strlen(s) + 1;
		str = (char *)malloc(sizeof(char) * lent);
		if (!(str))
			return (NULL);
		while (src[i] != '\0')
		{
			str[i] = f(j, src[i]);
			i++;
			j++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
