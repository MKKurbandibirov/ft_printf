/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:29:25 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/10/24 17:02:14 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	power(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static unsigned int	pow_10(int k)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < k)
	{
		res *= 10;
		i++;
	}
	return (res);
}

static void	solver(unsigned int n, char *res)
{
	int	len;
	int	i;

	i = 0;
	len = power(n);
	while (len > 0)
	{
		res[i] = '0' + (n / pow_10(len - 1)) % 10;
		len--;
		i++;
	}
	res[i] = '\0';
}

char	*ft_utoa(unsigned int n)
{
	char	*res;

	res = malloc((power(n) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	solver(n, res);
	return (res);
}
