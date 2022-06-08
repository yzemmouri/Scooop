/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:00:58 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:11:20 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*p_s2;

	i = 0;
	j = 0;
	p_s2 = (char *)s2;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (p_s2[j] != '\0')
	{
		s1[i] = p_s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
