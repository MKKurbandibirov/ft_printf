/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:02:59 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/11/15 17:41:44 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	power(unsigned long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static unsigned long int	pow_16(int k)
{
	int					i;
	unsigned long int	res;

	i = 0;
	res = 1;
	while (i < k)
	{
		res *= 16;
		i++;
	}
	return (res);
}

static void	solver(unsigned long int n, char *res, char *alf)
{
	int		len;
	int		i;

	i = 0;
	len = power(n);
	while (len > 0)
	{
		res[i] = alf[(n / pow_16(len - 1)) % 16];
		len--;
		i++;
	}
	res[i] = '\0';
}

char	*ft_ultoh(unsigned long int n, char *alf)
{
	char	*res;

	res = malloc((power(n) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	solver(n, res, alf);
	return (res);
}
