/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:57:56 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:11:52 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			s[i] = '\0';
			i++;
		}
	}
}