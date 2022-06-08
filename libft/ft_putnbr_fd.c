/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:18:25 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:10:39 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	pos;

	if (n >= 0)
	{
		pos = n;
	}
	else
	{
		ft_putchar_fd('-', fd);
		pos = n * -1;
	}
	if (pos >= 10)
		ft_putnbr_fd(pos / 10, fd);
	ft_putchar_fd(48 + pos % 10, fd);
}
