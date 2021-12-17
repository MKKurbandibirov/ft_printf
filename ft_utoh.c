/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:53:01 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/10/24 17:02:16 by nfarfetc         ###   ########.fr       */
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
		n /= 16;
		i++;
	}
	return (i);
}

static unsigned int	pow_16(int k)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < k)
	{
		res *= 16;
		i++;
	}
	return (res);
}

static void	solver(unsigned int n, char *res, char *alf)
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

char	*ft_utoh(unsigned int n, char *alf)
{
	char	*res;

	res = malloc((power(n) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	solver(n, res, alf);
	return (res);
}
